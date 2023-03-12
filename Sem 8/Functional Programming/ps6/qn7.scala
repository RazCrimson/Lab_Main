
def maxMin(l: Array[Int]): (Int, Int) = (l.reduce(_ min _), l.reduce(_ max _))

assert(maxMin(Array(1, 2, 3)) == (1, 3));
assert(maxMin(Array('a', 'b', 'c')) == ('a', 'c'));

