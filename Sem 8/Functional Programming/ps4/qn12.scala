// Qn 12

def checkTemps(x: Float,  y: Float): Boolean = if ((x < 0 || y < 0) && (x> 100 || y > 100)) true else false


assert(checkTemps(0, 0) == false)
assert(checkTemps(0, -1) == false)
assert(checkTemps(-1, 0) == false)
assert(checkTemps(100, 0) == false)
assert(checkTemps(101, 0) == false)
assert(checkTemps(0, 101) == false)
assert(checkTemps(101, -1) == true)
assert(checkTemps(-1, 101) == true)


println("checkTemps with (0, 0) is " + checkTemps(0, 0))
println("checkTemps with (0, -1) is " + checkTemps(0, -1))
println("checkTemps with (-1, 0) is " + checkTemps(-1, 0))
println("checkTemps with (100, 0) is " + checkTemps(100, 0))
println("checkTemps with (101, 0) is " + checkTemps(101, 0))
println("checkTemps with (0, 101) is " + checkTemps(0, 101))
println("checkTemps with (101, -1) is " + checkTemps(101, -1))
println("checkTemps with (-1, 101) is " + checkTemps(101, -1))
