// Qn 11

def checkIfStartswithSc(str: String): Boolean = if(str.length < 2) false else str(0) == 'S' && str(1) == 'c'


assert(checkIfStartswithSc("") == false)
assert(checkIfStartswithSc("test") == false)
assert(checkIfStartswithSc("Sctest") == true)
assert(checkIfStartswithSc("if Sc") == false)


println("checkIfStartswithSc with `test` is " + checkIfStartswithSc("test"))
println("checkIfStartswithSc with `if Sc` is " + checkIfStartswithSc("if Sc"))
println("checkIfStartswithSc with `Sctest` is " + checkIfStartswithSc("Sctest"))
println("checkIfStartswithSc with empty string is " + checkIfStartswithSc(""))
