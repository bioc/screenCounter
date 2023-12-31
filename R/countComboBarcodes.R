#' Count combinatorial barcodes
#'
#' Count combinatorial barcodes for single-end screen sequencing experiments where entities are distinguished based on random combinations of a small pool of known sequences within a single template.
#' 
#' @param fastq String containing the path to a FASTQ file containing single-end data,
#' or a connection object to such a file.
#' @param template A template for the barcode structure, see \code{?\link{parseBarcodeTemplate}} for details.
#' @param choices A \linkS4class{List} of character vectors, one per variable region in \code{template}.
#' The first vector should contain the potential sequences for the first variable region, 
#' the second vector for the second variable region and so on.
#' @param substitutions Integer scalar specifying the maximum number of substitutions when considering a match. 
#' @param strand String specifying which strand of the read to search.
#' @param find.best Logical scalar indicating whether to search each read for the best match.
#' Defaults to stopping at the first match.
#' @param indices Logical scalar indicating whether integer indices should be used to define each combinational barcode.
#' @param num.threads Integer scalar specifying the number of threads to use to process a single file.
#' @param files A character vector of paths to FASTQ files.
#' @param ... Further arguments to pass to \code{countComboBarcodes}.
#' @param withDimnames A logical scalar indicating whether the rows and columns should be named.
#' @param BPPARAM A \linkS4class{BiocParallelParam} object specifying how parallelization is to be performed across files.
#' 
#' @details
#' Certain screen sequencing experiments take advantage of combinatorial complexity to generate a very large pool of unique barcode sequences.
#' Only a subset of all possible combinatorial barcodes will be used in any given experiment.
#' This function only counts the combinations that are actually observed, improving efficiency over a more conventional approach (i.e., to generate all possible combinations and use \code{\link{countSingleBarcodes}} to count their frequency).
#'
#' If \code{strand="both"}, the original read sequence will be searched first.
#' If no match is found, the sequence is reverse-complemented and searched again.
#' Other settings of \code{strand} will only search one or the other sequence.
#' The most appropriate choice depends on both the sequencing protocol and the design (i.e., position and length) of the barcode.
#'
#' We can handle sequencing errors by setting \code{substitutions} to a value greater than zero.
#' This will consider substitutions in both the variable region as well as the constant flanking regions.
#'
#' By default, the function will stop at the first match that satisfies the requirements above.
#' If \code{find.best=TRUE}, we will instead try to find the best match with the fewest mismatches.
#' If there are multiple matches with the same number of mismatches, the read is discarded to avoid problems with ambiguity.
#'
#' @return 
#' \code{countComboBarcodes} returns a \linkS4class{DataFrame} where each row corresponds to a combinatorial barcode.
#' It contains \code{combinations}, a nested \linkS4class{DataFrame} that contains the sequences that define each combinatorial barcode;
#' and \code{counts}, an integer vector containing the frequency of each barcode.
#' The medata contains \code{nreads}, an integer scalar of the total number of reads in \code{fastq}.
#'
#' Each column of \code{combinations} corresponds to a single variable region in \code{template} and one vector in \code{choices}.
#' By default, the sequences are reported directly as character vectors.
#' If \code{indices=FALSE}, each column contains the indices of the sequences in the corresponding entry of \code{choices}.
#' 
#' \code{matrixOfComboBarcodes} returns a \linkS4class{SummarizedExperiment} containing:
#' \itemize{
#' \item An integer matrix named \code{"counts"}, containing counts for each combinatorial barcode in each \code{files}.
#' \item One or more vectors in the \code{rowData} that define each combinatorial barcode, equivalent to \code{combinations}.
#' \item Column metadata containing a character vector \code{files}, the path to each file;
#' an integer vector \code{nreads}, containing the total number of reads in each file;
#' and \code{nmapped}, containing the number of reads assigned to a barcode in the output count matrix.
#' }
#' If \code{withDimnames=TRUE}, row names are set to \code{"BARCODE_[ROW]"} and column names are set to \code{basename(files)}.
#'
#' @author Aaron Lun
#' @examples
#' # Creating an example dual barcode sequencing experiment.
#' known.pool <- c("AGAGAGAGA", "CTCTCTCTC",
#'     "GTGTGTGTG", "CACACACAC")
#' 
#' N <- 1000
#' barcodes <- sprintf("ACGT%sACGT%sACGT",
#'    sample(known.pool, N, replace=TRUE),
#'    sample(known.pool, N, replace=TRUE))
#' names(barcodes) <- seq_len(N)
#' 
#' library(Biostrings)
#' tmp <- tempfile(fileext=".fastq")
#' writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")
#'
#' # Counting the combinations.
#' output <- countComboBarcodes(tmp,
#'     template="ACGTNNNNNNNNNACGTNNNNNNNNNACGT",
#'     choices=list(first=known.pool, second=known.pool))
#' output$combinations
#' head(output$counts)
#'
#' matrixOfComboBarcodes(c(tmp, tmp),
#'     template="ACGTNNNNNNNNNACGTNNNNNNNNNACGT",
#'     choices=list(first=known.pool, second=known.pool))
#' @export
#' @importFrom S4Vectors metadata metadata<-
countComboBarcodes <- function(
    fastq, 
    template, 
    choices, 
    substitutions=0, 
    find.best=FALSE, 
    strand=c("both", "original", "reverse"), 
    num.threads=1, 
    indices=FALSE) 
{
    parsed <- parseBarcodeTemplate(template)
    n.pos <- parsed$variable$pos
    n.len <- parsed$variable$len
    constants <- parsed$constant
    template <- gsub("N", "-", template)

    # Validating 'choices'.
    nvariables <- length(n.pos)
    if (nvariables!=2L) {
        stop(sprintf("'length(choices)=%i' is not currently supported", nvariables))
    }
    if (nvariables!=length(choices)) {
        stop("'length(choices)' is not equal to the number of variable regions in 'template'")
    }
    for (i in seq_len(nvariables)) {
        if (!all(nchar(choices[[i]])==n.len[i])) {
            stop("each column of 'choices' must have same width as variable region in 'template'")
        }
    }

    strand <- c(original=0L, reverse=1L, both=2L)[match.arg(strand)]

    output <- count_combo_barcodes_single(fastq, template, strand, choices, substitutions, !find.best, num.threads)

    formatted <- .harvest_combinations(output, indices, choices)
    metadata(formatted)$nreads <- output[[3]]
    formatted
}

#' @importFrom S4Vectors DataFrame I
.harvest_combinations <- function(output, indices, choices) {
    keys <- DataFrame(t(output[[1]] + 1L))

    .names <- names(choices)
    if (is.null(.names)) {
        .names <- c("first", "second")
    }
    colnames(keys) <- .names

    if (!indices) {
        for (i in seq_len(ncol(keys))) {
            keys[,i] <- choices[[i]][keys[,i]]
        }
    }
    DataFrame(combinations=I(keys), counts=output[[2]])
}

#' @rdname countComboBarcodes
#' @export
#' @importFrom BiocParallel SerialParam bplapply
#' @importFrom S4Vectors DataFrame metadata
#' @importFrom SummarizedExperiment SummarizedExperiment
matrixOfComboBarcodes <- function(files, ..., withDimnames=TRUE, BPPARAM=SerialParam()) {
    out <- bplapply(files, FUN=countComboBarcodes, ..., BPPARAM=BPPARAM)
    combined <- do.call(combineComboCounts, out)
    mat <- combined$counts
    nreads <- vapply(out, function(x) metadata(x)$nreads, FUN.VALUE=0L)

    se <- SummarizedExperiment(list(counts=mat),
        rowData=combined$combinations,
        colData=DataFrame(paths=files, nreads=nreads, nmapped=colSums(mat)))

    if (withDimnames) {
        colnames(se) <- basename(files)
        rownames(se) <- sprintf("BARCODE_%i", seq_len(nrow(se)))
    }
    se
}
