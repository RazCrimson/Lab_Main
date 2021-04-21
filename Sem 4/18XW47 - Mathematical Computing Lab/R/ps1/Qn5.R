library(lpSolve)

f.obj <- c((5 + 0.03*40*3) * 8, (4 + 0.05*30*3)*8)

f.con <- matrix(c(40 * 8, 30 * 8,
                  1, 0,
                  0, 1),nrow=3, byrow=TRUE)

f.dir <- c(">=", "<=", "<=")

f.rhs <- c(2000, 9, 11)

lp1 <- lp("min", f.obj, f.con, f.dir, f.rhs, all.int = TRUE)

lp1$solution