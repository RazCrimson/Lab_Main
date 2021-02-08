concordance = {}
while True:
    line = input()
    if line:
        page_no = int(line[0])
        words = line[1:].split(" ")
        for word in words:
            if word in concordance:
                concordance[word].add(page_no)
            else:
                concordance[word] = {page_no}
        
    else:
        break

print(concordance)