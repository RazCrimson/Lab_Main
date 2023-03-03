
def replicateElements[A](l: List[A], n: Int): List[A] = List.tabulate(l.length)(x => List.fill(n)(l(x))).fold(List())((x, y) => x ++ y)

println(replicateElements(List(), 1))
println(replicateElements(List(1), 2))
println(replicateElements(List(1, 2), 4))
println(replicateElements(List(1, 2), 2))