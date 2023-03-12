
def avgArray(arr: Array[Int]): Float = arr.reduce(_ + _).toFloat / arr.length


assert(avgArray(Array(1, 2, 3)) == 2)
assert(avgArray(Array(1, 2, 3, 4)) == 2.5)