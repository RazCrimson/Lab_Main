
def checkIfSublist[A](a: List[A], b: List[A]): Boolean = b.forall(a contains _)


println(checkIfSublist(List(1, 2, 3, 4), List(1, 2)))
println(checkIfSublist(List(1, 2, 3, 4), List(4, 5)))
