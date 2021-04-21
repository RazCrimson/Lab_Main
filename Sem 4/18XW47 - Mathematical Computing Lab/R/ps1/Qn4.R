library(lpSolve)

f.obj <- c(3, 4)

f.con <- matrix(c(4, 2,
                  2, 5),nrow=2, byrow=TRUE)

f.dir <- c("<=", "<=")

f.rhs <- c(2 * 40, 3 * 60)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)

lp1$solution