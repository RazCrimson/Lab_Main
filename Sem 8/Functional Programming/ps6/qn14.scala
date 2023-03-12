

def removeDuplicates(arr: Array[Any]): Array[Any] = arr.foldLeft(Array[Any]())((res, value) => if(res contains value) res else res :+ value)


assert(removeDuplicates(Array(1, 1)).sameElements(Array(1)))
assert(removeDuplicates(Array(1, 2, 1, 3)).sameElements(Array(1, 2, 3)))
assert(removeDuplicates(Array(1, 2, 2, 3)).sameElements(Array(1, 2, 3)))