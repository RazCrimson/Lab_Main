
def largestSumContiguousSubArray(arr: Array[Int]) : Int = {
    var maxSoFar = arr.min
    var maxEndingHere = 0
    var start = 0
    var end = 0
    var s = 0
 
    for (i <- 0 to arr.length - 1) {
        maxEndingHere += arr(i);

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }

        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            s = i + 1;
        }
    }
    maxSoFar
}

assert(largestSumContiguousSubArray(Array(1, 2, -3, -4, 0, 6, 7, 8, 9)) == 30)