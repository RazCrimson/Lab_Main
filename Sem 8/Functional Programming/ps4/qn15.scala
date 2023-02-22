// Qn 15

def removeYtAt1(str: String): String = if(str.length < 3) str else if (str(1) == 'y' && str(2) == 't') s"${str(0)}${str.substring(3, str.length)}" else str
// Assumption: Only the first occurance of yt needs to be removed


assert(removeYtAt1("") == "")
assert(removeYtAt1("t") == "t")
assert(removeYtAt1("test") == "test")
assert(removeYtAt1("tytest") == "test")
assert(removeYtAt1("tesytt") == "tesytt")


println("removeYtAt1 with `` is " + removeYtAt1(""))
println("removeYtAt1 with `t` is " + removeYtAt1("t"))
println("removeYtAt1 with `test` is " + removeYtAt1("test"))
println("removeYtAt1 with `tytest` is " + removeYtAt1("tytest"))
println("removeYtAt1 with `tesytt` is " + removeYtAt1("tesytt"))