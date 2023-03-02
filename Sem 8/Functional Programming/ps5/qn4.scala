

def printSumAndProduct(l: List[Int]) = {
    l.foreach(println)
    println("Sum: " + l.fold(0)((x, y) => x + y))
    println("Product: " + l.fold(1)((x, y) => x * y))
}

printSumAndProduct(List(1, 2, 3, 4))