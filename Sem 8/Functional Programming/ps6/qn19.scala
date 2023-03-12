def lengthAfterDupsRemoval(arr: Array[Any]): Int = arr.foldLeft(Array[Any]())((newArr, value) => if(newArr contains value) newArr else newArr :+ value).length


assert(lengthAfterDupsRemoval(Array(1)) == 1)
assert(lengthAfterDupsRemoval(Array(1, 2)) == 2)
assert(lengthAfterDupsRemoval(Array(1, 1, 2)) == 2)
assert(lengthAfterDupsRemoval(Array(3, 1, 1, 2, 2)) == 3)