val lispList = 1 :: 2 :: 3 :: Nil
print("lispList: ")
println(lispList)

val javaList = List(1, 2, 3)
print("javaList: ")
println(javaList)

val rangeList = List.range(1, 4)
print("rangeList: ")
println(rangeList)

val tabulateList = List.tabulate(3)(n => n + 1)
print("tabulateList: ")
println(tabulateList)

val uniformList = List.fill(3)("test")
print("uniformList: ")
println(uniformList)
