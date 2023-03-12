
def checkPresence(arr: Array[Any], elem: Any): Boolean = arr contains elem

def checkFor3or6(arr: Array[Any]): Boolean = checkPresence(arr, 3) || checkPresence(arr, 6)


assert(checkFor3or6(Array(1)) == false)
assert(checkFor3or6(Array(1, 2)) == false)
assert(checkFor3or6(Array(1, 2, 3)) == true)
assert(checkFor3or6(Array(1, 2, 4, 5)) == false)
assert(checkFor3or6(Array(1, 2, 4, 5, 6)) == true)