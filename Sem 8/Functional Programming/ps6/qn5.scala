

def removeElem(arr: Array[Any], elem: Any): Boolean = {
    val index = arr.indexOf(elem);
    if(index == -1) return false;
    arr(index) = null;
    return true
}


var arr = Array[Any](1, 2, 43);
assert(removeElem(arr, 1) == true)
assert(arr.sameElements(Array[Any](null, 2, 43)))

arr = Array[Any](1, 2, 43)
assert(removeElem(arr, 43) == true)
assert(arr.sameElements(Array(1, 2, null)))


arr = Array[Any](1, 2, 43)
assert(removeElem(arr, 123) == false)
assert(arr.sameElements(Array(1, 2, 43)))
