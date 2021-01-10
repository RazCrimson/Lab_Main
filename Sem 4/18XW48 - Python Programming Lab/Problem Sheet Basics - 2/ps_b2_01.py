sequence = input("Please enter the string: ")

sequence_list = list(set(sequence.split(" ")))
sequence_list.sort()

print(" ".join(sequence_list))