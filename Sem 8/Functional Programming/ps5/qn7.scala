
def isEmpty[A](l: List[A]) = l.length == 0


assert(isEmpty(List()) == true);
assert(isEmpty(List(1)) == false);


println("isEmpty with (List(1, 2)) is : " + isEmpty(List(1, 2)))
println("isEmpty with (List(1, 1, 3)) is : " + isEmpty(List(1, 1, 3)))