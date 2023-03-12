def takeMiddle[T](arr: Array[T]): T = arr(arr.length/2)


def createMiddleElemArray(arrs: Array[Any]*): Array[Any] = arrs.map(takeMiddle).toArray


assert(createMiddleElemArray(Array(1), Array(2), Array(3)).sameElements(Array[Any](1, 2, 3)));
assert(createMiddleElemArray(Array(1, 2, 3), Array(4, 5, 6), Array(7, 8, 9)).sameElements(Array[Any](2, 5, 8)));
assert(createMiddleElemArray(Array(1, 2, 3), Array('a', 'b', 'c'), Array(7, 8, 9)).sameElements(Array[Any](2, 'b', 8)));
