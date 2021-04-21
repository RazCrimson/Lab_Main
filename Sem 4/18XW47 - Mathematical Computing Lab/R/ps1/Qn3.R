library(lpSolve)

f.obj <- c(7, 5)

f.con <- matrix(c(4, 3,
                  2, 1),nrow=2, byrow=TRUE)

f.dir <- c("<=", "<=")

f.rhs <- c(240, 100)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)

lp1$solution