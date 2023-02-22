// Qn 1

def customSum(x: Int, y: Int): Int = if (x != y) x + y else 3 * (x + y);


assert(customSum(1, 2) == 3);
assert(customSum(1, 1) == 6);


println("Sum of 1 & 2 is " + customSum(1, 2))
println("Sum of 2 & 2 is " + customSum(2, 2))

