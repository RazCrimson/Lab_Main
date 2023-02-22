// Qn 14

def checkIfAnyIn20To50(vals:Float*): Boolean = if (vals.exists((x:Float) => x < 51 && x > 21)) true else false


assert(checkIfAnyIn20To50(0, 0, 0) == false)
assert(checkIfAnyIn20To50(0, -1, 10) == false)
assert(checkIfAnyIn20To50(100, 0, 25) == true)
assert(checkIfAnyIn20To50(101, 30, 25) == true)
assert(checkIfAnyIn20To50(0, 101, 44) == true)
assert(checkIfAnyIn20To50(30, 0, 31) == true)
assert(checkIfAnyIn20To50(99, 201, 70) == false)


println("checkIfAnyIn20To50 with (0, 0, 0) is " + checkIfAnyIn20To50(0, 0, 0))
println("checkIfAnyIn20To50 with (0, -1, 10) is " + checkIfAnyIn20To50(0, -1, 10))
println("checkIfAnyIn20To50 with (100, 0, 25) is " + checkIfAnyIn20To50(100, 0, 25))
println("checkIfAnyIn20To50 with (101, 30, 25) is " + checkIfAnyIn20To50(101, 30, 25))
println("checkIfAnyIn20To50 with (0, 101, 44) is " + checkIfAnyIn20To50(0, 101, 44))
println("checkIfAnyIn20To50 with (30, 0, 31) is "  + checkIfAnyIn20To50(30, 0, 31))
println("checkIfAnyIn20To50 with (99, 201, 70) is " + checkIfAnyIn20To50(99, 201, 70))