temp_sequence = [3, 6, 9, 12, 15, 21, 24]

a = temp_sequence
c = a[3:5]

b = a.copy() # Question mentions to make a copy not a reference

del a[3:5]
a[3:3] = c

print(a)
