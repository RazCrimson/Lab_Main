def has22(arr):
    for i in range(len(arr) - 1):
        if(arr[i] == 2 and arr[i + 1] == 2):
            return True
    return False


n = int(input("Enter no of elements : ")) 
arr = [int(input()) for i in range(0, n)]
    
if has22(arr):
    print("Has 22")
else:
    print("Dosent have 22")