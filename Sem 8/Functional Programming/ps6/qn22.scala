def closestPairSumTo0(arr: Array[Int]): Tuple2[Int, Int] = {
    var minSum = arr(0) + arr(1)
    var iMin = 0
    var jMin = 1

    for(i <- 1 to arr.length - 2) {
        for(j <- i to arr.length - 1) {
            val sum = arr(i) + arr(j)
            if (sum.abs < minSum.abs) {
                minSum = sum
                iMin = i
                jMin = j
            }
        }
    }
    (arr(iMin), arr(jMin))
}

assert(closestPairSumTo0(Array(-1, 2, -4, 5, 6, -7, 8)) == (-1, 2))
assert(closestPairSumTo0(Array(-1, 2, -2, -4, 5, 6, -7, 8)) == (2, -2))