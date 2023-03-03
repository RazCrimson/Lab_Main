
def getNthElem[A](l: List[A], n: Int): A = if (n > -1 && n < l.length) l(n) else throw new RuntimeException("Index out of bounds")


println(getNthElem(List(1, 2, 3, 4), 1))
println(getNthElem(List(1, 2, 3, 4), 2))