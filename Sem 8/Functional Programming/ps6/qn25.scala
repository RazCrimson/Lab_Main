
def oddEven(arr: Array[Int]): Array[Int] = arr.filter(x => (x & 0x1) == 1) ++ arr.filter(x => (x & 0x1) == 0)


assert(oddEven(Array(1, 2)).sameElements(Array(1, 2)))
assert(oddEven(Array(1, 2, 3, 4)).sameElements(Array(1, 3, 2, 4)))
assert(oddEven(Array(1, 2, 2, 3, 4, 5)).sameElements(Array(1, 3, 5, 2, 2, 4)))