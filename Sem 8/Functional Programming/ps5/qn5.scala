

def maxElem(l: List[Int]): Int = l.reduce((x , y) => if (x < y) y else x)
def minElem(l: List[Int]): Int = l.reduce((x , y) => if (x < y) x else y)

assert(maxElem(List(1, 2, 3)) == 3);
assert(minElem(List(1, 2, 3)) == 1);
assert(maxElem(List('a', 'b', 'c')) == 'c');
assert(minElem(List('a', 'b', 'c')) == 'a');


println("maxElem with (List(1, 2, 3)) is : " + maxElem(List(1, 2, 3)))
println("minElem with (List(1, 2, 3)) is : " + maxElem(List(1, 2, 3)))
println("maxElem with (List('a', 'b', 'c')) is : " + maxElem(List('a', 'b', 'c')).toChar)
println("minElem with (List('a', 'b', 'c')) is : " + maxElem(List('a', 'b', 'c')).toChar)