
def countTriangles(arr: Array[Int]):Int = {
    val sorted = arr.sortWith(_ < _)
    var count = 0

    for(i <- sorted.length - 1 to 1 by -1){
        var l = 0;
        var r = i - 1;
        while(l<r){
            if (sorted(l) + sorted(r) > sorted(i)){
                count += r - l;
                r -= 1
            }
            else {
                l += 1
            }
        }
    }
    count
}

assert(countTriangles(Array(10, 21, 22, 100, 101, 200, 300)) == 6)