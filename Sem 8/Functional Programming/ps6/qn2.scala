

def checkIfInHeadOrLast[A](arr: Array[A], elem: A): Boolean = elem == arr.head || elem == arr.last


assert(checkIfInHeadOrLast(Array(1, 2, 43), 1) == true)
assert(checkIfInHeadOrLast(Array(1, 2, 43), 43) == true)
assert(checkIfInHeadOrLast(Array(1, 2, 43), 2) == false)