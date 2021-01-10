string = input("Enter the string: ")
string = set(string.lower())
chars = [ ch for ch in string if ord(ch) in range(ord('a'), ord('z')+1)] 
  
if len(chars) == 26:
    print("It is a panagram")
else:
    print("It is not a panagram")