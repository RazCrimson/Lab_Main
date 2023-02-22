// Qn 9

def checkIfMultiple(num: Int, divisor: Int): Boolean = if (num % divisor == 0) true else false


def checkIfMultipleOf3Or7(num: Int): Boolean = checkIfMultiple(num, 3) || checkIfMultiple(num, 7)


assert(checkIfMultipleOf3Or7(3) == true)
assert(checkIfMultipleOf3Or7(7) == true)
assert(checkIfMultipleOf3Or7(6) == true)
assert(checkIfMultipleOf3Or7(21) == true)
assert(checkIfMultipleOf3Or7(14) == true)
assert(checkIfMultipleOf3Or7(22) == false)


println("checkIfMultipleOf3Or7 with `3` is " + checkIfMultipleOf3Or7(3))
println("checkIfMultipleOf3Or7 with `7` is " + checkIfMultipleOf3Or7(7))
println("checkIfMultipleOf3Or7 with `6` is " + checkIfMultipleOf3Or7(6))
println("checkIfMultipleOf3Or7 with `21` is " + checkIfMultipleOf3Or7(21))
println("checkIfMultipleOf3Or7 with `14` is " + checkIfMultipleOf3Or7(14))
println("checkIfMultipleOf3Or7 with `22` is " + checkIfMultipleOf3Or7(22))