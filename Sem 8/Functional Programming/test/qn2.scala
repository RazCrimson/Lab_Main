// From Bharath Vignesh J K (19PW08) 
// Functional Programming Lab - Final Lab Test
// QN 2

import scala.io.StdIn


def stringCompareWithoutCase(s1: String, s2:String) = s1.toLowerCase() == s2.toLowerCase()

// Basic Assertions
assert(stringCompareWithoutCase("", "") == true)
assert(stringCompareWithoutCase("hello", "HELLO") == true)
assert(stringCompareWithoutCase("hellow", "helloW") == true)
assert(stringCompareWithoutCase("hellow123", "helloW123") == true)
assert(stringCompareWithoutCase("hello123!$^&here", "hello123!$^&HERE") == true)
assert(stringCompareWithoutCase("hello", "hello1") == false)

// Interative Query to test function
print("Enter String 1: ")
val string1 = StdIn.readLine()

print("Enter String 2: ")
val string2 = StdIn.readLine()

println("Comparing both string ignoring case: " + stringCompareWithoutCase(string1, string2))
