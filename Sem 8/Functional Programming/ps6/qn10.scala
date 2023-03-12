def reverseArray(arr: Array[Int]): Array[Int] = arr.reverse


assert(reverseArray(Array()).sameElements(Array[Int]()))
assert(reverseArray(Array(1)).sameElements(Array(1)))
assert(reverseArray(Array(1, 2)).sameElements(Array(2, 1)))
assert(reverseArray(Array(1, 2, 3)).sameElements(Array(3, 2, 1)))
assert(reverseArray(Array(1, 2, 3, 4)).sameElements(Array(4, 3, 2, 1)))