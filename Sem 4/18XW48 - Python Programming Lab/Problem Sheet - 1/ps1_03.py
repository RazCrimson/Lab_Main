def get_dictionary(dna_string):
    base_pair_list = ["A", "G", "T", "C"]
    base_pair_dictionary = dict.fromkeys(base_pair_list, 0)
    for char in dna_string:
        base_pair_dictionary[char] += 1
    return base_pair_dictionary


dna_string = input("Enter the input string: ")
print(get_dictionary(dna_string))