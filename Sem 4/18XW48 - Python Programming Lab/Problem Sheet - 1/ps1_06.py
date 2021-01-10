words_dictionary = {
    "converse":"conserve",
    "tests":"text",
    "abc":"acb"
}

def print_metathesis_pairs(words_dictionary):
    for key, val in words_dictionary.items():
        if(len(key) != len(val)):
            continue
        key_list = list(key)
        val_list = list(val)
        for i in range(len(key_list)):
            if key_list[i] != val_list[i]:
                index = val_list.index(key_list[i])
                temp = val_list[i]
                val_list[i] = val_list[index]
                val_list[index] = temp
                if(str(key_list) == str(val_list)):
                    print(key + " and " + val + " is a metathesis pair in the given dictionary.")


print_metathesis_pairs(words_dictionary)
