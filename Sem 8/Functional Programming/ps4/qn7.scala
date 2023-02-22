// Qn 7

def quadrapleFirst2Chars(str: String): String = if (str.length < 2) str else str.substring(0, 2) * 4


assert(quadrapleFirst2Chars("") == "")
assert(quadrapleFirst2Chars("t") == "t")
assert(quadrapleFirst2Chars("te") == "tetetete")
assert(quadrapleFirst2Chars("test") == "tetetete")


println("quadrapleFirst2Chars with `` is " + quadrapleFirst2Chars(""))
println("quadrapleFirst2Chars with `t` is " + quadrapleFirst2Chars("t"))
println("quadrapleFirst2Chars with `te` is " + quadrapleFirst2Chars("te"))
println("quadrapleFirst2Chars with `test` is " + quadrapleFirst2Chars("test"))
