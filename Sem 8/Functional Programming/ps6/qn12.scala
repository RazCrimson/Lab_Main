
def checkMaxOfFirstLastMiddle(arr: Array[Int]): Int = {
    if((arr.length & 0x1) != 1) throw new RuntimeException("Not an odd length Array") 
    Array(arr(0), arr.length, arr(arr.length/2)).reduce((x, y) => x.max(y))
}


assert(checkMaxOfFirstLastMiddle(Array(1)) == 1)
assert(checkMaxOfFirstLastMiddle(Array(1, 2, 3)) == 3)
assert(checkMaxOfFirstLastMiddle(Array(1, 3, 2)) == 3)
assert(checkMaxOfFirstLastMiddle(Array(3, 1, 2)) == 3)
assert(checkMaxOfFirstLastMiddle(Array(6, 2, 4, 5, 2)) == 6)