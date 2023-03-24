// From Bharath Vignesh J K (19PW08) 
// Functional Programming Lab - Final Lab Test
// QN 1


import java.lang.IndexOutOfBoundsException  // For testing getNthElem with invalid index

def removeDuplicatesIfNotEmpty(l: List[Any]) = if (l.isEmpty) l else l.distinct

def mergeLists(l1: List[Any], l2: List[Any]) = l1 ++ l2

def reverseList(l: List[Any]) = l.reverse

def checkPalindrome(l: List[Any]) = l == reverseList(l)

def getNthElem(l:List[Any], index: Int) = l(index)

def procedure1(l1: List[Any],l2: List[Any]): Boolean = 
{
    // Performs all the steps except getting Nth Element and returns
    // a bool indicating if the result is a palindrome or not 
    val list1 = removeDuplicatesIfNotEmpty(l1)
    val list2 = removeDuplicatesIfNotEmpty(l2)
    println("List 1 after first 2 steps: "+ list1)
    println("List 2 after first 2 steps: "+ list2)
    
    val merged = mergeLists(list1, list2)
    println("Merged List: "+ merged)
    
    val reversed = reverseList(merged)
    println("Reverse of Merged List: "+ reversed)

    checkPalindrome(merged)
}


// Assertions and display results 

// procedure1
println("\nAll Cases for procedure1:")

val case1List1 = List(1, 2, 3)
val case1List2 = List(3, 2, 1)
println(s"\nprocedure1($case1List1, $case1List2):")
val case1 = procedure1(case1List1, case1List2)
println("Merged list is a palindrome: " + case1)
assert(case1 == true)

val case2List1 = List(1, 2, 2, 2, 3)
val case2List2 = List(3, 3, 3, 3, 2, 1)
println(s"\nprocedure1($case2List1, $case2List2):")
val case2 = procedure1(case2List1, case2List2)
println("Merged list is a palindrome: " + case2)
assert(case2 == true)

val case3List1 = List(1, 2, 4, 4)
val case3List2 = List(3, 3, 3, 3, 2, 1)
println(s"\nprocedure1($case3List1, $case3List2):")
val case3 = procedure1(case3List1, case3List2)
println("Merged list is a palindrome: " + case3)
assert(case3 == false)


// getNthElem
println("\nAll Cases for getNthElem:")
val pCaseInput = List(1, 2, 3, 4, 5)

println(s"\ngetNthElem($pCaseInput, 0):")
val pCase1 = getNthElem(pCaseInput, 0)
println("Result: " + pCase1)
assert(pCase1 == 1)

println(s"\ngetNthElem($pCaseInput, 2):")
val pCase2 = getNthElem(pCaseInput, 2)
println("Result: " + pCase2)
assert(pCase2 == 3)

println(s"\ngetNthElem($pCaseInput, 10):")
try{
    val pCase3 = getNthElem(pCaseInput, 10)
    println("Failed!!!!") // Should not reach this part as index is out of bounds
} catch { 
    case e:IndexOutOfBoundsException => println("Caused an expected IndexOutOfBoundsException")
}

import scala.io.StdIn

println("Enter the number of elements in arr1:")
val count1 = StdIn.readInt()
var testL1: List[Int] = List[Int]()
for(i <- 0 until count1) {
    var readVal = StdIn.readInt()
    testL1 = testclear
}
val testL2: List[Int] = StdIn.readLine()
val res = procedure1(case3List1, case3List2)
print(res)
