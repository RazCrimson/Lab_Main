// Qn 17

def capitalizeLast4Chars(str: String): String = if (str.length < 4) str.toUpperCase() else str.substring(0, str.length - 4) + str.substring(str.length - 4, str.length).toUpperCase()


assert(capitalizeLast4Chars("") == "")
assert(capitalizeLast4Chars("tes") == "TES")
assert(capitalizeLast4Chars("test") == "TEST")
assert(capitalizeLast4Chars("testt") == "tESTT")
assert(capitalizeLast4Chars("testtt") == "teSTTT")
assert(capitalizeLast4Chars("testttt") == "tesTTTT")


println("capitalizeLast4Chars with `` is " + capitalizeLast4Chars(""))
println("capitalizeLast4Chars with `tes` is " + capitalizeLast4Chars("tes"))
println("capitalizeLast4Chars with `test` is " + capitalizeLast4Chars("test"))
println("capitalizeLast4Chars with `testt` is " + capitalizeLast4Chars("testt"))
println("capitalizeLast4Chars with `testtt` is " + capitalizeLast4Chars("testtt"))
println("capitalizeLast4Chars with `testttt` is " + capitalizeLast4Chars("testttt"))