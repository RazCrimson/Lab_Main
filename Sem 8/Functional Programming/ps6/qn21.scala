
def sort0And1(arr: Array[Int]): Array[Int] = arr.filter(_ == 0) ++ arr.filter(x => x != 0 && x != 1) ++ arr.filter(_ == 1)


assert(sort0And1(Array(0, 1, 0)).sameElements(Array(0, 0, 1)))
assert(sort0And1(Array(1, 1, 0)).sameElements(Array(0, 1, 1)))
assert(sort0And1(Array(0, 1, 2 , 0)).sameElements(Array(0, 0, 2,  1)))