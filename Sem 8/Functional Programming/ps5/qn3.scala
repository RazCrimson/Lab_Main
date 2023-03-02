def removeFromList[A](list: List[A], elements: A* ) = list diff elements


assert(removeFromList(List(1, 2, 3), 1, 2, 4) == List(3));
assert(removeFromList(List('a', 'b', 'c'), 'b', 'c') == List('a'));


println("removeFromList with (List(1, 2, 3), 1, 2, 4) is : " + removeFromList(List(1, 2, 3), 1, 2, 4))
println("removeFromList with (List('a', 'b', 'c'), 'b', 'c') is : " + removeFromList(List('a', 'b', 'c'), 'b', 'c'))