

def secondLargest(arr: Array[Int]): Int = {
    if(arr.length < 2) throw new RuntimeException("Need an array of length atleast 2")
    arr.foldLeft(arr.min)((cur2Max, value) => if(value > cur2Max && value < arr.max) value else cur2Max)
}

assert(secondLargest(Array(1, 2, 3)) == 2)
assert(secondLargest(Array(1, 3, 2)) == 2)
assert(secondLargest(Array(3, 1, 2)) == 2)
assert(secondLargest(Array(6, 2, 4, 5, 1)) == 5)