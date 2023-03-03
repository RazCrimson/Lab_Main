

def triplicateElements[A](l: List[A]): List[A] = List.tabulate(l.length)(x => List.fill(3)(l(x))).fold(List())((x, y) => x ++ y)

println(triplicateElements(List()))
println(triplicateElements(List(1)))
println(triplicateElements(List(1, 2)))