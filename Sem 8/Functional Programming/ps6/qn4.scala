

def checkIfInHeadAndLastAreSame[A](arr: Array[A]): Boolean = arr.head == arr.last


assert(checkIfInHeadAndLastAreSame(Array(1)) == true)
assert(checkIfInHeadAndLastAreSame(Array(1, 1)) == true)
assert(checkIfInHeadAndLastAreSame(Array(1, 2, 1)) == true)
assert(checkIfInHeadAndLastAreSame(Array(1, 2, 43)) == false)