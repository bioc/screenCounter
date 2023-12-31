# This tests countSingleBarcodes().
# library(testthat); library(screenCounter); source("setup.R"); source("test-single.R")

library(Biostrings)
nbarcodes <- 20
POOL <- vapply(rep(10, nbarcodes), GENERATE_RANDOM_SEQ, FUN.VALUE="")

barcode.fmt <- "ACGT%sTGCA"
template <- sprintf(barcode.fmt, strrep("N", nchar(POOL[1])))

STICKER <- function(barcodes, fname, out, ..., strandFUN=identity) {
    ADD_FLANKS(barcodes, fname, strandFUN=strandFUN)
    out2 <- countSingleBarcodes(fname, template=template, ...)
    expect_identical(out, out2)

    # Nothing at the start, flanking on the right.
    ADD_FLANKS(barcodes, fname, nleft=0, strandFUN=strandFUN)
    out2 <- countSingleBarcodes(fname, template=template, ...)
    expect_identical(out, out2)

    # Nothing at the end, flanking on the left.
    ADD_FLANKS(barcodes, fname, nright=0, strandFUN=strandFUN)
    out2 <- countSingleBarcodes(fname, template=template, ...)
    expect_identical(out, out2)
}

CHECK_OUTPUT <- function(out, tab, choices, N) {
    expect_identical(tab, out$counts)
    expect_identical(choices, out$choices)
    expect_identical(as.integer(N), metadata(out)$nreads) 
}

test_that("countSingleBarcodes works as expected in basic mode", {
    for (N in c(1, 10, 100, 1000)) {
        i <- sample(nbarcodes, N, replace=TRUE)
        barcodes <- sprintf(barcode.fmt, POOL[i])
        names(barcodes) <- seq_len(N)

        tmp <- tempfile(fileext=".fastq")
        writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")

        out <- countSingleBarcodes(tmp, POOL, template=template)
        tab <- tabulate(i, nbins=nbarcodes)
        CHECK_OUTPUT(out, tab, POOL, N)

        # Same results when you stick a bunch of random crap to the start and end.
        STICKER(barcodes, tmp, out, choices=POOL)

        # Same results with find.best=TRUE.
        best <- countSingleBarcodes(tmp, POOL, template=template, find.best=TRUE)
        expect_identical(out, best)
    }
})

test_that("countSingleBarcodes works as expected with substitutions", {
    barcodes <- c(
        "ACGTGGGGGGGGGGTGCA",
        "ACGTGGGGCGGGGGTGCA",
        "ACGTGGGGCCGGGGTGCA", # not matched, two substitutions.
        "ACGTGGGGGGGGGGTTCA", 
        "CCGTGGGGGGGGGGTGCA"  
    )
    names(barcodes) <- seq_along(barcodes)

    tmp <- tempfile(fileext=".fastq")
    writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")

    choices <- strrep(BASES, 10)
    out <- countSingleBarcodes(tmp, choices, template=template, sub=TRUE)
    CHECK_OUTPUT(out, c(0L, 0L, 4L, 0L), choices, length(barcodes))

    STICKER(barcodes, tmp, out, choices=choices, sub=TRUE)

    # Handles conflicts correctly.
    barcodes <- c(
        "ACGTCCCCCCCCCCTGCA", 
        "ACGTCCCCCCCCCATGCA",
        "ACGTCCCCCCCCCGTGCA", # ambiguous and removed.
        "ACGTCCCCCCCCCTTGCA"  # ambiguous and removed.
    )
    names(barcodes) <- seq_along(barcodes)

    tmp <- tempfile(fileext=".fastq")
    writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")

    choices <- c("CCCCCCCCCC", "CCCCCCCCCA")
    out <- countSingleBarcodes(tmp, choices, template=template, sub=TRUE)
    CHECK_OUTPUT(out, c(1L, 1L), choices, length(barcodes))

    STICKER(barcodes, tmp, out, choices=choices, sub=TRUE)
})

test_that("countSingleBarcodes works as expected with strands", {
    for (strand in c("original", "reverse", "both")) {
        i <- sample(nbarcodes, 1000, replace=TRUE)
        barcodes <- sprintf(barcode.fmt, POOL[i])
        names(barcodes) <- seq_along(i)

        B <- DNAStringSet(barcodes)
        strandFUN <- CHOOSE_STRAND_FUN(strand)
        tmp <- tempfile(fileext=".fastq")
        writeXStringSet(strandFUN(B), filepath=tmp, format="fastq")

        out <- countSingleBarcodes(tmp, POOL, template=template, strand=strand)
        tab <- tabulate(i, nbins=nbarcodes)
        CHECK_OUTPUT(out, tab, POOL, length(B)) 

        # Same results when you stick a bunch of random crap to the start and end.
        STICKER(barcodes, tmp, out, choices=POOL, strand=strand, strandFUN=strandFUN)
    }
})

test_that("matrixOfSingleBarcodes works as expected with names", {
    i <- sample(nbarcodes, 10, replace=TRUE)
    barcodes <- sprintf(barcode.fmt, POOL[i])
    names(barcodes) <- seq_len(10)

    tmp <- tempfile(fileext=".fastq")
    writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")

    mat <- matrixOfSingleBarcodes(tmp, POOL, template=template)
    expect_identical(colnames(mat), basename(tmp))
    expect_identical(rownames(mat), POOL)
})

test_that("countSingleBarcodes works as expected with IUPAC codes", {
    choices <- c("AAAAABAAAA", "CCCCCDCCCC", "GGGGGHGGGG", "TTTTTVTTTT")
    pool <- c(
        "AAAAACAAAA", 
        "AAAAAGAAAA", 
        "AAAAAAAAAA", # doesn't match
        "CCCCCACCCC", 
        "CCCCAACCCC", # mismatch in the wrong place.
        "GGGGGTGGGG", 
        "TTTTTGTTTT"
    )
    barcodes <- sprintf(barcode.fmt, pool)
    names(barcodes) <- seq_along(barcodes)

    tmp <- tempfile(fileext=".fastq")
    writeXStringSet(DNAStringSet(barcodes), filepath=tmp, format="fastq")

    mat <- countSingleBarcodes(tmp, choices, template=template, strand="original")
    expect_identical(mat$counts, c(2L, 1L, 1L, 1L))

    mat <- countSingleBarcodes(tmp, choices, template=template, strand="original", substitutions=1L)
    expect_identical(mat$counts, c(3L, 2L, 1L, 1L))
})

