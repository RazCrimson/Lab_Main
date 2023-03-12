

def diffMaxMin(arr: Array[Int]): Int = arr.max - arr.min

assert(diffMaxMin(Array(1)) == 0)
assert(diffMaxMin(Array(1, 2)) == 1)
assert(diffMaxMin(Array(3, 1, 2)) == 2)
assert(diffMaxMin(Array(6, 2, 4, 5, 1)) == 5)