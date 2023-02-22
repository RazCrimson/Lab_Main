// Qn 4

def prependIfNotPresent(str: String): String = if(str contains "if") str else "if" + str


assert(prependIfNotPresent("") == "if")
assert(prependIfNotPresent("test") == "iftest")
assert(prependIfNotPresent("if test") == "if test")
assert(prependIfNotPresent("test if") == "test if")


println("prependIfNotPresent with `test` is " + prependIfNotPresent("test"))
println("prependIfNotPresent with empty string is " + prependIfNotPresent(""))
println("prependIfNotPresent with `if test` is " + prependIfNotPresent("if test"))
println("prependIfNotPresent with `test if` is " + prependIfNotPresent("test if"))