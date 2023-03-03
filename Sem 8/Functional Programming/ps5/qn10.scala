
def index[A](l: List[A], elem: A): Int = l.indexWhere(e => e == elem)


assert(index(List(1), 2) == -1);
assert(index(List(1), 1) == 0);


println("index with (List(1), 1) is : " + index(List(1), 1))
println("index with (List(1), 2) is : " + index(List(1), 2))