
def customSum(arr: Array[Int]): Int = if (arr.length > 3) arr.slice(arr.length - 3, arr.length).reduce(_ + _) else arr.fold(0)(_ + _)

assert(customSum(Array()) == 0)
assert(customSum(Array(1)) == 1)
assert(customSum(Array(1, 2)) == 3)
assert(customSum(Array(1, 2, 3)) == 6)
assert(customSum(Array(1, 2, 3, 4)) == 9)