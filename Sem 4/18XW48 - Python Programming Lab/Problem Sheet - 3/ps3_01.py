def delete_consonants(string):
    return ''.join([x for x in string if x.lower() in ['a','e','i','o','u']])
    
if __name__ == '__main__' :
    print(input('Enter the string : '))
