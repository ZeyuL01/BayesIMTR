
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
# devtools::install_github("ZeyuL01/BayesIMTR")
library(BayesIMTR)
```

If you meet a compilation problem,

for mac users please refer to:
<https://thecoatlessprofessor.com/programming/cpp/r-compiler-tools-for-rcpp-on-macos/>

for windows users please refer to:
<https://cran.r-project.org/bin/windows/base/howto-R-devel.html>

or submit your questions, we are happy to answer them.

## Load ChIP-seq data

Pre-compiled ChIP-seq database can be accessed through:
<https://smu.box.com/s/mhpelp5zro7538pbfkfj65xf61842huo>

``` r
#Please download the chip-seq file and unzip it to a local directory.
#For example: /Users/user/Desktop/data/ChIP-seq

#The function below just need to run once to setup.
#bin_width has to map with the loaded chip-seq file, we have three options: 100/500/1000.
chip_path = "/Users/zeyulu/Dropbox/datasets/macs2_peak_inds"
load_chip_data(chip_path, bin_width = 1000)
#> Warning in load_chip_data(chip_path, bin_width = 1000): Overwriting previous
#> loaded meta-table for bin width of 1000
#> [1] "ChIP-seq data successfully loaded, please run BayesIMTR with input to check!"
#> NULL
```

## How to run BayesIMTR.

It is very simple to run **BayesIMTR** as long as you have the peak file
derived from a common peak-calling algorithm, or any interested regions
you have defined in advance. The input file should has format of
bed/narrowPeak/broadPeak/bigNarrowPeak.

``` r
#As an example, the user-input peak set file path is "/Users/user/Desktop/input.bed"
input_path = "/Users/zeyulu/Dropbox/datasets/ATAC_seq/LSD1.bed"
KDM1A_test<-BayesIMTR(input_path,format = "bed", N = 1000, bin_width = 1000)
#> [1] "Load and map peaks to bins..."
#> [1] "Done."
#> [1] "Align the loaded peaks with the pre-compiled reference ChIP-seq data, bin width used: 1000 bps"
#> ==================================================[1] "Done."
#> [1] "Start BayesIMTR core, rounds: 1000"
#> [1] "Done."
KDM1A_results<-Show_Results(KDM1A_test, burnin=500)

head(KDM1A_results[["Theta_ij"]],10)
#>       TF   Theta_ij Rank_ij
#> 1  EP400 -0.8773744       1
#> 2    MAX -1.0570827       2
#> 3   E2F1 -1.1435641       3
#> 4   E2F1 -1.1445906       4
#> 5   E2F1 -1.1535106       5
#> 6   E2F1 -1.1595503       6
#> 7   E2F1 -1.1623126       7
#> 8  EP400 -1.1657020       8
#> 9  FOXM1 -1.1717745       9
#> 10   MAX -1.1756919      10
head(KDM1A_results[["Theta_i"]],10)
#>         TF   Theta_i Rank_i
#> 1     CTCF -2.132505      1
#> 2     BRD4 -2.394264      2
#> 3      MYC -2.451317      3
#> 4    RAD21 -2.504698      4
#> 5  SMARCA4 -2.573826      5
#> 6     BRD2 -2.600666      6
#> 7      MAX -2.694076      7
#> 8      YY1 -2.698606      8
#> 9     E2F1 -2.706367      9
#> 10   KMT2A -2.712215     10
```

## Example

This is a basic example which shows you how to get the Demo results used
in **BayesIMTR** manuscript:

``` r
library(BayesIMTR)
library(kableExtra)

##package has three demo knock-out experiment derived datasets c("CTCF","KDM1A","ZBTB7A").
##can take ~10 mins to finish for 1000 rounds.
CTCF_Demo_mat <- Demo(1000,"CTCF")
#> [1] "Time used: 3.57 mins for 1000 rounds."

##Show_Results can summarize the results from Gibbs sampler.
##must specify the burnin.
CTCF_Results <- Show_Results(CTCF_Demo_mat,burnin=500)
CTCF_Theta_ij_db <- CTCF_Results[["Theta_ij"]]
CTCF_Theta_i_db <- CTCF_Results[["Theta_i"]]

head(CTCF_Theta_ij_db,10)
#>        TF  Theta_ij Rank_ij
#> 1   STAG2 -1.712195       1
#> 2   KDM5B -1.719792       2
#> 3   STAG1 -1.728437       3
#> 4  ZNF143 -1.736784       4
#> 5  ZNF143 -1.765139       5
#> 6   STAG1 -1.778640       6
#> 7   RAD21 -1.788137       7
#> 8    CTCF -1.788369       8
#> 9     MAX -1.791676       9
#> 10  STAG1 -1.792464      10
```

As we can see, CTCF is ranked into the top 10 TF in the final result.

We may also check the higher level parameters that integrate information
from individual ChIP-seq tracks to give one unique rank to each TF.

``` r
head(CTCF_Theta_i_db,10)
#>         TF   Theta_i Rank_i
#> 1     CTCF -2.174598      1
#> 2    RAD21 -2.637728      2
#> 3     BRD4 -2.824603      3
#> 4      MYC -2.910842      4
#> 5     BRD2 -2.938484      5
#> 6  SMARCA4 -2.952932      6
#> 7     SMC3 -2.963305      7
#> 8    RUNX1 -2.980558      8
#> 9    STAG1 -2.982588      9
#> 10   SMC1A -2.986643     10
```

This time CTCF is ranked even higher to the top 1 position over all 1476
TFs.
