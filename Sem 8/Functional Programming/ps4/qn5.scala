// Qn 5

def removeCharAtIndex(str: String, index: Int): String = {
    val (prestr, poststr) = str.splitAt(index);
    return prestr ++ poststr.tail
}


assert(removeCharAtIndex("test", 2) == "tet")
assert(removeCharAtIndex("hello", 2) == "helo")


println("removeCharAtIndex with `test` and 2 is " + removeCharAtIndex("test", 2))
println("removeCharAtIndex with `hello` and 2 is " + removeCharAtIndex("hello", 2))