
def fourSum(arr: Array[Int], targetSum: Int): Array[Int] = arr.combinations(4).filter(_.sum == targetSum).next()


assert(fourSum(Array(1, 1, 1, 1, 1, 2), 5).sameElements(Array[Int](1, 1, 1, 2)))