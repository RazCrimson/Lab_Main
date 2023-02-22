// Qn 8

def padByLastChar(str: String): String =  str.last + str + str.last;


assert(padByLastChar("h") == "hhh")
assert(padByLastChar("he") == "ehee")
assert(padByLastChar("hello") == "ohelloo")


println("padByLastChar with `h` is " + padByLastChar("h"))
println("padByLastChar with `he` is " + padByLastChar("he"))
println("padByLastChar with `hello` is " + padByLastChar("hello"))

