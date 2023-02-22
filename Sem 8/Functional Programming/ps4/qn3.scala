// Qn 3

def isOrSumTo30(x: Int, y: Int): Boolean =  if (x < 0 || y < 0) false else if(x == 30 || y == 30 || x + y == 30) true else false


assert(isOrSumTo30(10, 20) == true)
assert(isOrSumTo30(30, -10) == false)
assert(isOrSumTo30(0, 0) == false)
assert(isOrSumTo30(1, 2) == false)
assert(isOrSumTo30(15, 20) == false)


println("isOrSumTo30 of (10, 20) is " + isOrSumTo30(10, 20))
println("isOrSumTo30 of (30, -10) is " + isOrSumTo30(30, -10))
println("isOrSumTo30 of (0, 0) is " + isOrSumTo30(0, 0))
println("isOrSumTo30 of (1, 2) is " + isOrSumTo30(1, 2))
println("isOrSumTo30 of (15, 20) is " + isOrSumTo30(15, 20))

