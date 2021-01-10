import random

words = ['evaporate']
word = random.choice(words)
guess_count = 6
word_now = ['_' for x in range(len(word)) ]
print('Welcome to Hangman!')
print(" ".join(word_now))
while guess_count != 0:
    print(f'Chances left - {guess_count}')
    char = input('Guess your letter : ').lower()
    if char not in word :
        if guess_count > 1 :
            print('Incorrect!')
        else :
            print('Lost :(')
        guess_count += -1
        
    else :
        pos_list = [i for i, x in enumerate(word) if x == char]
        for x in pos_list:
            if word_now[x] == '_':
                word_now[x] = char
            else :
                print('Guessed already !')
                break
        print(" ".join(word_now))
    
    if '_' not in word_now :
        print('Won :)')
        break

print('Game Over!')