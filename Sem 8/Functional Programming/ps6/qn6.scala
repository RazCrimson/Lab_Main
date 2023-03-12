

def rotateLeft(arr: Array[Any]): Array[Any] = if (arr.length < 1) arr else arr.tail :+ arr.head


assert(rotateLeft(Array(1)).sameElements(Array(1)))
assert(rotateLeft(Array(1, 2)).sameElements(Array(2, 1)))
assert(rotateLeft(Array(1, 2, 3)).sameElements(Array(2, 3, 1)))