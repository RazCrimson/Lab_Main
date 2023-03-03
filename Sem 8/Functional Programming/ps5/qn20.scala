
def countOccurances[A](l: List[A]) = l.groupMapReduce(identity)(_ => 1)( _ + _)


println(countOccurances(List(1, 2, 3, 5, 2, 3, 4)))

