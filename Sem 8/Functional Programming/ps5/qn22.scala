
def length[A](l: List[A]): Int = l.map(_ => 1).reduce(_ + _)

println(length(List(1, 2, 3)))