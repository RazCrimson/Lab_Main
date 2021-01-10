def centered_average(arr):
    maximum = arr[0]
    minimum = arr[0]
    sum_count = 0
    for x in range(len(arr)):
        maximum = max(maximum, x)
        minimum = min(minimum, x)
        sum_count += x
    return (sum_count - maximum - minimum) / (len(arr) - 2)

n = int(input("Enter no of elements : ")) 
arr = [int(input()) for i in range(0, n)]
print("Centered average :" + centered_average(arr))
