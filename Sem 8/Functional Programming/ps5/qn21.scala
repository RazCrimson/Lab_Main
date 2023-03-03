
def splitList[A](l: List[A], index: Int): (List[A], List[A]) = (l.slice(0, index), l.slice(index, l.length))


println(splitList(List(1, 2, 3, 4, 5, 6, 7, 8), 4))
