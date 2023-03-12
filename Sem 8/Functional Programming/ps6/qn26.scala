

def maxProductPair(arr: Array[Int]): Tuple2[Int, Int] = {
    var i = 0
    var j = 1
    var iMax = i
    var jMax = j

    var maxProd = arr(i) * arr(j)
    for(i <- 1 to arr.length - 2){
        for(j <- i + 1 to arr.length - 1){
            val prod = arr(i) * arr(j)
            if(prod > maxProd){
                maxProd = prod
                iMax = i
                jMax = j
            }
        }
    }
    (arr(iMax), arr(jMax))
}

assert(maxProductPair(Array(2, 3, 5, 7, -7, 5, 8, -5)) == (7, 8))
