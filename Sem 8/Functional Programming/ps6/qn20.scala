
def twoSmallest(arr: Array[Int]): Tuple2[Int, Int] = (arr.min, arr.filter(x => x != arr.min).min)


assert(twoSmallest(Array(1, 2, 3)) == (1, 2))
assert(twoSmallest(Array(1, 2, 3, 4, 5)) == (1, 2))