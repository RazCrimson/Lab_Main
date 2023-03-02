def addToList[A](list: List[A], elements: A* ) = list ++ elements


assert(addToList(List('a'), 'b', 'c') == List('a', 'b', 'c'));
assert(addToList(List(1, 2, 3), 1, 2, 4) == List(1, 2, 3, 1, 2, 4));


println("addToList with (List('a'), 'b', 'c') is : " + addToList(List('a'), 'b', 'c'))
println("addToList with (List(1, 2, 3), 1, 2, 4) is : " + addToList(List(1, 2, 3), 1, 2, 4))