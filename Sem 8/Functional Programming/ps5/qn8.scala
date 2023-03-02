
def diff[A](l1: List[A], l2: List[A]): List[A] = l1.filterNot((l2 contains _))


print(diff(List(1, 2, 3), List(2, 3, 4)))