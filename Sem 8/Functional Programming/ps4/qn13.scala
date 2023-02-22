// Qn 13

def checkIfAnyIn100To200(x: Float,  y: Float): Boolean = if ((x < 201 && x > 99) || (y < 201 && y > 99)) true else false


assert(checkIfAnyIn100To200(0, 0) == false)
assert(checkIfAnyIn100To200(0, -1) == false)
assert(checkIfAnyIn100To200(100, 0) == true)
assert(checkIfAnyIn100To200(101, 0) == true)
assert(checkIfAnyIn100To200(0, 101) == true)
assert(checkIfAnyIn100To200(200, 0) == true)
assert(checkIfAnyIn100To200(99, 200) == true)
assert(checkIfAnyIn100To200(201, 0) == false)
assert(checkIfAnyIn100To200(99, 201) == false)


println("checkIfAnyIn100To200 with (0, 0) is " + checkIfAnyIn100To200(0, 0))
println("checkIfAnyIn100To200 with (0, -1) is " + checkIfAnyIn100To200(0, -1))
println("checkIfAnyIn100To200 with (100, 0) is " + checkIfAnyIn100To200(100, 0))
println("checkIfAnyIn100To200 with (101, 0) is " + checkIfAnyIn100To200(101, 0))
println("checkIfAnyIn100To200 with (0, 101) is " + checkIfAnyIn100To200(0, 101))
println("checkIfAnyIn100To200 with (200, 0) is " + checkIfAnyIn100To200(200, 0))
println("checkIfAnyIn100To200 with (99, 200) is " + checkIfAnyIn100To200(99, 200))
println("checkIfAnyIn100To200 with (201, 0) is " + checkIfAnyIn100To200(201, 0))
println("checkIfAnyIn100To200 with (99, 201) is " + checkIfAnyIn100To200(99, 201))
