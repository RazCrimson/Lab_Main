def commonElems(arr1: Array[Any], arr2: Array[Any]): Array[Any] =  arr1.filter((x) => arr2 contains x)


assert(commonElems(Array(1), Array(1)).sameElements(Array(1)))
assert(commonElems(Array(1, 2), Array(1, 3)).sameElements(Array(1)))
assert(commonElems(Array(1, 2), Array(2, 3)).sameElements(Array(2)))