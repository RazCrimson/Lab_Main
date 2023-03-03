
def isPalindrome[A](l:List[A]): Boolean = l == l.reverse

println(isPalindrome(List()))
println(isPalindrome(List(1, 1)))
println(isPalindrome(List(1, 2, 1)))
println(isPalindrome(List(1, 2, 3, 1)))