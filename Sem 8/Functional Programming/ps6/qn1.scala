

def sumArray(arr: Array[Int]): Int = arr.fold(0)(_ + _)


assert(sumArray(Array(1, 2, 3)) == 6)
assert(sumArray(Array(1, 2, 3, 4)) == 10)