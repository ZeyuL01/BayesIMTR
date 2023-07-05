
<!-- README.md is generated from README.Rmd. Please edit that file -->

# BayesIMTR

<!-- badges: start -->
<!-- badges: end -->

The goal of **BayesIMTR** is to identify the potential master
transcriptional regulators with the input derived from chromatin
accessibility profiling methods(e.g. ATAC-seq, DNase-seq, MNase-seq),
the input can be either a file that stores the information of “peaks”
generated by common peak-calling algorithms (e.g. MACS2, Homer) or
user-defined regions, such as peaks from a differential accessibility
analysis(e.g. DiffBind).

## Installation

You can install the development version of BayesIMTR from
[GitHub](https://github.com/ZeyuL01/BayesIMTR) with:

``` r
# install.packages("devtools")
devtools::install_github("ZeyuL01/BayesIMTR")
```

## Example

This is a basic example which shows you how to run **BayesIMTR**:

``` r
library(BayesIMTR)
#> Loading required package: RcppArmadillo
#> Loading required package: RcppDist
#> Loading required package: RcppProgress

##package has three demo knock-out experiment derived datasets c("CTCF","KDM1A","ZBTB7A")
##can take ~10 mins to finish for 1000 rounds.
CTCF_Demo_mat <- Demo(1000,"CTCF")
#> [1] "Time used: 3.57 mins for 1000 rounds."
```

Let’s see the results of CTCF demo data.

``` r
##Show_Results can summarize the results from Gibbs sampler.
##must specify the burnin
CTCF_Results <- Show_Results(CTCF_Demo_mat,burnin=500)
CTCF_Theta_ij_db <- CTCF_Results[["Theta_ij"]]
CTCF_Theta_i_db <- CTCF_Results[["Theta_i"]]

head(CTCF_Theta_ij_db,10)
#>        TF  Theta_ij Rank_ij
#> 1   STAG2 -1.711725       1
#> 2   KDM5B -1.719854       2
#> 3   STAG1 -1.730364       3
#> 4  ZNF143 -1.736727       4
#> 5  ZNF143 -1.765155       5
#> 6   STAG1 -1.779381       6
#> 7   RAD21 -1.787433       7
#> 8    CTCF -1.788355       8
#> 9     MAX -1.791023       9
#> 10  STAG1 -1.793131      10
```

As we can see, CTCF is ranked into the top 10 TF in the final result.

We may also check the higher level parameters that integrate information
from individual ChIP-seq tracks to give one unique rank to each TF.

``` r
head(CTCF_Theta_i_db,10)
#>         TF   Theta_i Rank_i
#> 1     CTCF -2.174761      1
#> 2    RAD21 -2.639377      2
#> 3     BRD4 -2.824606      3
#> 4      MYC -2.910914      4
#> 5     BRD2 -2.938636      5
#> 6  SMARCA4 -2.952647      6
#> 7     SMC3 -2.962993      7
#> 8    RUNX1 -2.980765      8
#> 9    STAG1 -2.982066      9
#> 10   SMC1A -2.986807     10
```

This time CTCF is ranked even higher to the top 1 position over all 1476
TFs.
