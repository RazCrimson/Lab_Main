
def findFromLastPosition[A](l: List[A], index: Int, elem: A): Int = l.slice(0, index).lastIndexWhere(e => e == elem)


println(findFromLastPosition(List(1), 1, 1))
println(findFromLastPosition(List(1, 2, 3, 4), 3, 2))
println(findFromLastPosition(List(1, 2, 3, 4), 1, 2))