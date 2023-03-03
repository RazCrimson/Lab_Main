

def reverseList[A](l: List[A]): List[A] = List.tabulate(l.length)(n => l(l.length - n - 1))


println(reverseList(List()))
println(reverseList(List(1)))
println(reverseList(List(1, 2, 3)))