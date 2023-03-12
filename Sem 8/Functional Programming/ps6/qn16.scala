

def secondSmallest(arr: Array[Int]): Int = {
    if(arr.length < 2) throw new RuntimeException("Need an array of length atleast 2")
    arr.foldLeft(arr.max)((cur2Min, value) => if(value < cur2Min && value > arr.min) value else cur2Min)
}

assert(secondSmallest(Array(1, 2, 3)) == 2)
assert(secondSmallest(Array(1, 3, 2)) == 2)
assert(secondSmallest(Array(3, 1, 2)) == 2)
assert(secondSmallest(Array(6, 2, 4, 5, 1)) == 2)