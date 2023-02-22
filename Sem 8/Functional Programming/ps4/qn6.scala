// Qn 6

def replaceFirstAndLast(str: String, replacement: Char): String = if (str.length <= 1)  if (str.length == 1) s"$replacement" else "" else s"$replacement${str.init.tail}$replacement";


assert(replaceFirstAndLast("", '1') == "")
assert(replaceFirstAndLast("h", '1') == "1")
assert(replaceFirstAndLast("he", '1') == "11")
assert(replaceFirstAndLast("hello", '1') == "1ell1")


println("replaceFirstAndLast with `` and '1' is " + replaceFirstAndLast("", '1'))
println("replaceFirstAndLast with `h` and '1' is " + replaceFirstAndLast("h", '1'))
println("replaceFirstAndLast with `he` and '1' is " + replaceFirstAndLast("he", '1'))
println("replaceFirstAndLast with `hello` and '1' is " + replaceFirstAndLast("hello", '1'))


