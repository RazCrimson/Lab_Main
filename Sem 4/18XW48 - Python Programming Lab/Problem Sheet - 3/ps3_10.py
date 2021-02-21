"""
A simple program to solve sudoku

Author: Raz Crimson 
"""

ALL_ELEMENTS = {1, 2, 3, 4, 5, 6, 7, 8, 9}

def find_next_empty_entry(board, i, j):
    '''
    finds then next empty location in the board
    returns -1, -1 if all location are filled
    '''
    for x in range(i, 9):
        for y in range(j, 9):
            if board[x][y] == 0:
                return x, y

    for x in range(i):
        for y in range(j):
            if board[x][y] == 0:
                return x, y

    return -1, -1

    
def get_possible_elements(board, i, j):
    '''computes a list of possible elemets that can be placed at a location'''
    current_elements = set()
    for x in range(9):
        if board[i][x] != 0:
            current_elements.add(board[i][x])
        if board[x][j] != 0:
            current_elements.add(board[x][j])
    i = i//3 * 3
    j = j//3 * 3            
    for x in range(3):
        for y in range(3):
            if board[i + x][j + y] != 0:
                current_elements.add(board[i + x][j + y])
    return list(ALL_ELEMENTS.difference(current_elements))

def solve_sudoku(board, i = 0, j = 0):
    i, j = find_next_empty_entry(board, i , j)
    if i == -1:
        return True
    possible_elements = get_possible_elements(board, i ,j)
    for element in possible_elements:
        board[i][j] = element
        if solve_sudoku(board, i , j):
            return True
        board[i][j] = 0

    return False
    

def print_board(board):
    '''prints the board in the sudoku format'''
    for x in range(9):
        for y in range(9):
            print(board[x][y], end=' ')
            if y == 2 or y == 5:
                print(end=' ')
        print()
        if x == 2 or x == 5:
            print()

if __name__ == '__main__':
    num = int(input('Enter the number of problems : '))
    for _ in range(num):
        string = input('Enter the problem in a single line')
        # Simple input validation
        if string.isdigit() is False or len(string) != 81:
            print('Invalid Input!')
            exit(0)

        board = []
        for x in range(9):
            board.append([int(char) for char in list(string)[x*9: (x+1)*9]])
        print('The Current Board is :')
        print_board(board)
        
        print('\n\nFinding solution... ', end='')
        if solve_sudoku(board):
            print('Found!')
            print_board(board)
        else: 
            print('No solution can be found!')
