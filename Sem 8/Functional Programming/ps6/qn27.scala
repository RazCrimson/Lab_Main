
def orderAsSecondLargest(arr: Array[Int]): Array[Int] = {
    val n = arr.length;
    var tmp: Int = 0;

    for (i <- 1 to n - 1 by +2) {
        if (arr(i - 1) > arr(i)) {
            tmp = arr(i - 1);
            arr(i - 1) = arr(i)
            arr(i) = tmp
        }

        if (i + 1 < n && arr(i + 1) > arr(i)) {
            tmp = arr(i + 1);
            arr(i + 1) = arr(i)
            arr(i) = tmp
        }
    }
    arr
}

assert(orderAsSecondLargest(Array[Int](1, 2, 4, 9, 5, 3, 8, 7, 10, 12, 14)).sameElements(Array(1, 4, 2, 9, 3, 8, 5, 10, 7, 14, 12)))