lines = input("Enter the sentence: ").split(". ")
sentences = []
word_set = set()

for line in lines:
    words = line.split(':')[1].split()
    sentences.append([line.split(":")[0],words])

for num, words in sentences:
    for word in words:
        word_set.add(word)
dictionary = {word : set() for word in word_set}

for word in word_set:
    for index, word_list in sentences:
        if word in word_list:
            dictionary[word].add(index)
print(dictionary)