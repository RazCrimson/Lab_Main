

def removeDuplicates[A](l: List[A]) = l.distinctBy((x) => x)


assert(removeDuplicates(List(1, 2)) == List(1, 2));
assert(removeDuplicates(List(1, 1, 3)) == List(1, 3));


println("removeDuplicates with (List(1, 2)) is : " + removeDuplicates(List(1, 2)))
println("removeDuplicates with (List(1, 1, 3)) is : " + removeDuplicates(List(1, 1, 3)))