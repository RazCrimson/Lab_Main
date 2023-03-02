
def firstAndLast[A](l: List[A]): (A, A) = (l.head , l.last)


assert(firstAndLast(List(1)) == (1, 1));
assert(firstAndLast(List(1 , 2)) == (1, 2));


println("firstAndLast with (List(1)) is : " + firstAndLast(List(1)))
println("firstAndLast with (List(1, 2)) is : " + firstAndLast(List(1, 2)))