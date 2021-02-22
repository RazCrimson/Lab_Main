def abbreviations(fullname):
    splited_names = fullname.split(" ")
    if len(splited_names) != 1:
        result = [x[0].upper() for x in splited_names[:-1]]
        result.append(splited_names[-1])
        return ". ".join(result)
    return splited_names[0]

if __name__ == '__main__':
    print(abbreviations(input('Enter your fullname : ')))