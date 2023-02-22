// Qn 10

def padByLast3Char(str: String): String = {
    val len = if (str.length < 3) str.length else 3;
    s"${str.substring(0, len)}$str${str.substring(0, len)}"
}


assert(padByLast3Char("") == "")
assert(padByLast3Char("h") == "hhh")
assert(padByLast3Char("he") == "hehehe")
assert(padByLast3Char("hello") == "helhellohel")


println("padByLast3Char with `` is " + padByLast3Char(""))
println("padByLast3Char with `h` is " + padByLast3Char("h"))
println("padByLast3Char with `he` is " + padByLast3Char("he"))
println("padByLast3Char with `hello` is " + padByLast3Char("hello"))

