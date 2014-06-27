#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]

arma::mat  mat_mul_arma(arma::mat A,
			arma::mat B) {
  arma::mat C = (A * B);
  return C;
}


/*** R

library(microbenchmark)
amat <- matrix(as.numeric(1:9),   nrow=3)
bmat <- matrix(as.numeric(10:18), nrow=3)

mat_mul_arma(amat, bmat)

amat %*% bmat

microbenchmark(
  amat %*% bmat,
  mat_mul_arma(amat, bmat)
)

bigMat1 <- matrix(runif(1000000), nrow=1000)
bigMat2 <- matrix(runif(1000000), nrow=1000)

all.equal(bigMat1 %*% bigMat2,
          mat_mul_arma(bigMat1, bigMat2))

microbenchmark(
  bigMat1 %*% bigMat2,
  mat_mul_arma(bigMat1, bigMat2)
)

*/
