
def avgWithoutMaxMin(arr:Array[Int]): Float = arr.filter((x) => x != arr.max && x != arr.min).foldLeft(0)((x, y) => x + y)/(arr.length - 2).max(1).toFloat


assert(avgWithoutMaxMin(Array(1)) == 0)
assert(avgWithoutMaxMin(Array(1, 2)) == 0)
assert(avgWithoutMaxMin(Array(3, 1, 2)) == 2)
assert(avgWithoutMaxMin(Array(3, 1, 2, 2)) == 2)