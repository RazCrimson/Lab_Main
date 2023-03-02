
def oddEven[A](l: List[A]): (List[A], List[A]) = (l.zipWithIndex.filter(_._2 % 2 == 1).map(_._1), l.zipWithIndex.filter(_._2 % 2 == 0).map(_._1))


println(oddEven(List(0, 1, 2, 3, 4)))