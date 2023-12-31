% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/countPairedComboBarcodes.R
\name{countPairedComboBarcodes}
\alias{countPairedComboBarcodes}
\alias{matrixOfPairedComboBarcodes}
\title{Count paired-end combinatorial barcodes}
\usage{
countPairedComboBarcodes(
  fastq,
  choices,
  flank5,
  flank3,
  template = NULL,
  substitutions = 0,
  find.best = FALSE,
  strand = "original",
  num.threads = 1,
  randomized = FALSE,
  indices = FALSE
)

matrixOfPairedComboBarcodes(
  files,
  ...,
  withDimnames = TRUE,
  BPPARAM = SerialParam()
)
}
\arguments{
\item{fastq}{Character vector of length 2, containing paths to two FASTQ files with paired-end data.}

\item{choices}{A \linkS4class{List} of two character vectors.
The first vector should contain the potential sequences for the variable region in the first template,
the second vector for the variable region in the second template.}

\item{flank5}{Character vector of length 2 containing the constant sequence on the 5' flank of the variable region for barcodes 1 and 2, respectively.
Alternatively, a string can be supplied if the constant sequence is the same for each barcode.}

\item{flank3}{Character vector of length 2 containing the constant sequence on the 3' flank of the variable region for barcodes 1 and 2, respectively.
Alternatively, a string can be supplied if the constant sequence is the same for each barcode.}

\item{template}{Character vector of length 2 containing the template for the structure of barcodes 1 and 2, respectively.
Alternatively, a string can be supplied if the template is the same for each barcode.}

\item{substitutions}{Integer vector of length 2 specifying how many substitutions should be allowed for barcodes 1 and 2, respectively.
Alternatively, an integer scalar can be supplied if this is the same for each barcode.}

\item{find.best}{Logical scalar indicating whether to search each read for the best match.
Defaults to stopping at the first match.}

\item{strand}{Character vector of length 2 specifying which strand of the read to search (\code{"original"}, \code{"reverse"}) for each barcode.
Alternatively, a string can be supplied if this is the same for each barcode.}

\item{num.threads}{Integer scalar specifying the number of threads to use to process a single file.}

\item{randomized}{Logical scalar indicating whether the first FASTQ file always contains the first barcode in \code{choices}.
If not, the opposite orientation is also searched.}

\item{indices}{Logical scalar indicating whether integer indices should be used to define each combinational barcode.}

\item{files}{A list of character vectors of length 2 containing paths to paired FASTQ files.}

\item{...}{Further arguments to pass to \code{countDualBarcodes}.}

\item{withDimnames}{A logical scalar indicating whether the rows and columns should be named.}

\item{BPPARAM}{A \linkS4class{BiocParallelParam} object specifying how parallelization is to be performed across files.}
}
\value{
\code{countPairedComboBarcodes} returns a \linkS4class{DataFrame} where each row corresponds to a combinatorial barcode.
It contains \code{combinations}, a nested \linkS4class{DataFrame} that contains the sequences that define each combinatorial barcode;
and \code{counts}, an integer vector containing the frequency of each barcode.
The medata contains: 
\itemize{
\item \code{npairs}, the total number of read pairs processed by the function.
\item \code{barcode1.only}, the number of read pairs that only match to barcode 1.
\item \code{barcode2.only}, the number of read pairs that only match to barcode 2.
}

Each column of \code{combinations} corresponds to a single variable region in \code{template} and one vector in \code{choices}.
By default, the sequences are reported directly as character vectors.
If \code{indices=FALSE}, each column contains the indices of the sequences in the corresponding entry of \code{choices}.

\code{matrixOfPairedComboBarcodes} returns a \linkS4class{SummarizedExperiment} containing:
\itemize{
\item An integer matrix named \code{"counts"}, containing counts for each combinatorial barcode in each \code{files}.
\item One or more vectors in the \code{rowData} that define each combinatorial barcode, equivalent to \code{combinations}.
\item Column metadata containing a character vector \code{files}, the path to each file;
an integer vector \code{nreads}, containing the total number of reads in each file;
and \code{nmapped}, containing the number of reads assigned to a barcode in the output count matrix.
}
}
\description{
Count combinatorial barcodes for paired-end screen sequencing experiments where entities are distinguished based on random combinations of a small pool of known sequences across two templates.
}
\details{
Here, we consider a barcode design very similar to that of \code{\link{countComboBarcodes}},
except that the two variable regions are present on different reads rather than occurring within a single template on the same read.
This function counts the frequency of these barcode combinations across the two reads.

The interpretation of the arguments for matching each barcode to reads is similar to that of \code{\link{countSingleBarcodes}}.
Each barcode in the combination can be associated with different search parameters;
for example, the search for the \dQuote{first} barcode in \code{choices[[1]]}
will be performed with \code{flank5[1]}, \code{flank3[1]}, \code{substitutions[1]}, \code{strand[1]}, etc.

By default, the first FASTQ file is assumed to contain the first barcode (i.e., \code{choices[[1]]})
while the second file is assumed to contain the second barcode (\code{choices[[2]]}).
However, if \code{randomized=TRUE}, the orientation is assumed to be random such that the first FASTQ file may contain the second barcode and so on.
In such cases, both orientations will be searched to identify the combination.
This is most relevant when the constant regions are different between the two reads, otherwise either orientation could be valid.

We can handle sequencing errors by setting \code{substitutions} to a value greater than zero.
This will consider substitutions in both the variable region as well as the constant flanking regions for each read.

By default, the function will stop at the first match that satisfies the requirements above.
If \code{find.best=TRUE}, we will instead try to find the best match with the fewest mismatches.
If there are multiple matches with the same number of mismatches, the read is discarded to avoid problems with ambiguity.
}
\examples{
# Creating an example dual barcode sequencing experiment.
known.pool1 <- c("AGAGAGAGA", "CTCTCTCTC", "GTGTGTGTG", "CACACACAC")
known.pool2 <- c("ATATATATA", "CGCGCGCGC", "GAGAGAGAG", "CTCTCTCTC")
choices <- list(barcode1=known.pool1, barcode2=known.pool2)

N <- 1000
read1 <- sprintf("CAGCTACGTACG\%sCCAGCTCGATCG", sample(known.pool1, N, replace=TRUE))
names(read1) <- seq_len(N)

read2 <- sprintf("TGGGCAGCGACA\%sACACGAGGGTAT", sample(known.pool2, N, replace=TRUE))
names(read2) <- seq_len(N)

library(Biostrings)
tmp <- tempfile()
tmp1 <- paste0(tmp, "_1.fastq")
writeXStringSet(DNAStringSet(read1), filepath=tmp1, format="fastq")
tmp2 <- paste0(tmp, "_2.fastq")
writeXStringSet(DNAStringSet(read2), filepath=tmp2, format="fastq")

# Counting the combinations.
countPairedComboBarcodes(c(tmp1, tmp2), choices=choices, 
    template=c("CAGCTACGTACGNNNNNNNNNCCAGCTCGATCG",
               "TGGGCAGCGACANNNNNNNNNACACGAGGGTAT"))

matrixOfPairedComboBarcodes(list(c(tmp1, tmp2)),
    template=c("CAGCTACGTACGNNNNNNNNNCCAGCTCGATCG",
               "TGGGCAGCGACANNNNNNNNNACACGAGGGTAT"),
    choices=list(first=known.pool1, second=known.pool2))

}
\author{
Aaron Lun
}
