// Qn 2
import scala.math.abs

def randoDiffFunc2(n: Int, x: Int = 51): Int = {
    val diff = abs(n - x);
    if (diff <= x) diff else 3 * diff;
}


assert(randoDiffFunc2(10) == 41);
assert(randoDiffFunc2(200) == 447);


println("randoDiffFunc2 of 10 is " + randoDiffFunc2(10))
println("randoDiffFunc2 of 200 is " + randoDiffFunc2(200))

