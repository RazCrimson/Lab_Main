// Qn 16

def countChar(str: String, chr: Char, count: Int = 0): Boolean = {
    if (count > 5)
        return true
    else if (str.length == 0){
        return if(count < 5 && count > 1) true else false
    }
    else {
        countChar(str.tail, chr, count + (if (str(0) == chr) 1 else 0 ));
    }

}


assert(countChar("", 't') == false)
assert(countChar("tes", 't') == false)
assert(countChar("test", 't') == true)
assert(countChar("testt", 't') == true)
assert(countChar("testtt", 't') == true)
assert(countChar("testttt", 't') == false)


println("countChar with `` and 't' is " + countChar("", 't'))
println("countChar with `tes` and 't' is " + countChar("tes", 't'))
println("countChar with `test` and 't' is " + countChar("test", 't'))
println("countChar with `testt` and 't' is " + countChar("testt", 't'))
println("countChar with `testtt` and 't' is " + countChar("testtt", 't'))
println("countChar with `testttt` and 't' is " + countChar("testttt", 't'))