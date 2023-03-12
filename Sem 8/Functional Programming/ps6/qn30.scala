def minSubArrayLen(target: Int, nums: Array[Int]): Int = {
		var subArrSum = 0
		var minSubArr = Integer.MAX_VALUE
		var last = 0

		for (i <- 0 to nums.length - 1)
		{
			subArrSum += nums(i)
			if (i + 1 >= target)
			{
				if (minSubArr > subArrSum)
				{
					minSubArr = subArrSum
					last = i
				}

				subArrSum -= nums(i + 1 - target);
			}
		}
		minSubArr;
}

assert(minSubArrayLen(4, Array(1, 2, 3, 4, 5, 6, 7, 8, 9,10)) == 10)