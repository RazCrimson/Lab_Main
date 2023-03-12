def maxOrderedDiff(arr: Array[Int]): Int = {
    var i = 0
    var j = 1
    var maxDiff = (arr(i).abs - arr(j).abs).abs

    for(i <- 1 to arr.length - 2){
        for(j <- i + 1 to arr.length - 1){
            val diff = (arr(i).abs - arr(j).abs).abs
            if(diff > maxDiff){
                maxDiff = diff
            }
        }
    }
    maxDiff
}

assert(maxOrderedDiff(Array(2, 3, 1, 7, 9, 5, 11, 3, 5)) == 10)



