'''
Program for Set 3 for Final Lab test of Python Lab

Author: Bharath Vignesh J K(19PW08)
'''

# The Class required to be implemented
class SMS_Store:
    def __init__(self) -> None:
        '''Initializes the SMS store object'''
        self.__internal_message_box = []    # Internal messagebox list

    def add_new_arrival(self, from_number, time_arrived, text_of_SMS: str) -> None:
        '''Appends newer messages to the internal message box with the `has_been_viewed` set to False'''
        message_tuple = False, from_number, time_arrived, text_of_SMS
        self.__internal_message_box.append(message_tuple)

    def message_count(self):
        return len(self.__internal_message_box)

    def __index_in_range_check(self, i:  int, *, raise_exceptions=False) -> bool:
        '''Internally used index checking methods'''
        if -1 < i < len(self.__internal_message_box):
            return True
        elif raise_exceptions is True:
            raise IndexError(
                'Index is beyond the range of the internal message box')
        return False

    def get_unread_indexes(self):
        '''Returs list of indices that has `has_been_viewed` set to False'''
        indexes = []
        for i, message_tuple in enumerate(self.__internal_message_box):
            has_been_viewed, _, _, _ = message_tuple
            if has_been_viewed is False:
                indexes.append(i)
        return indexes

    def get_message(self, i: int) -> tuple:
        '''
        Returns (from_number, time_arrived, text_of_sms) if i in range of internal mailbox
        otherwise returns None.
        Also changes `has_been_viewed` state to True if the message was retieved for first time.
        '''
        if not self.__index_in_range_check(i):
            return None

        message_tuple = self.__internal_message_box[i]
        has_been_viewed, from_number, time_arrived, text_of_SMS = message_tuple

        # Update internal list if the message is retieved for the first time
        if has_been_viewed is False:
            self.__internal_message_box[i] = True, from_number, time_arrived, text_of_SMS
        return (from_number, time_arrived, text_of_SMS)

    def delete(self, i: int):
        '''Deletes the message at that index'''
        if self.__index_in_range_check(i):
            del self.__internal_message_box[i]

    def clear(self):
        '''Clears the internal message box of all messages'''
        self.__internal_message_box = []


# Additional classes and function for easier user interactions with
# the class

class UserInputError(Exception):
    '''A custom exception to indicate the user input a invalid value'''

def int_converter(string: str) -> int:
    try:
        return int(string)
    except ValueError:
        raise UserInputError


# Main Function
if __name__ == '__main__':
    my_inbox = SMS_Store()

    print('Press Ctrl + C to terminate program')
    while True:
        try:
            print('\n\nChoices:\n1. Add Message\n2. Print Message Count\n3. List unread Indices\n4. Print message\n5. Delete Message\n6. Clear')
            inp = input('Enter your choice: ')

            ch = int_converter(inp) 

            if ch == 1:
                from_number = input('Enter from number :')
                time_arrived = input('Enter the time arrived :')
                text_of_SMS = input('Enter of the text of the SMS :')
                my_inbox.add_new_arrival(from_number, time_arrived, text_of_SMS)

            elif ch == 2:
                print(f'Message Count : {my_inbox.message_count()}')

            elif ch == 3:
                print(f'Unread Indices : {my_inbox.get_unread_indexes()}')

            elif ch == 4:
                inp = input('Enter the Index of the message to retrieve : ')
                index = int_converter(inp)
                msg = my_inbox.get_message(index)
                print(f'Message Tuple: ', msg)

            elif ch == 5:
                inp = input('Enter the Index of the message to delete : ')
                index = int_converter(inp)
                my_inbox.delete(index)

            elif ch == 6:
                my_inbox.clear()
            
            else:
                raise UserInputError

        except KeyboardInterrupt:
            print('Program termianted!')
            break

# Testing is done in testing.py
# A sample out put is present below:


# Output
# Press Ctrl + C to terminate program
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 1
# Enter from number :1
# Enter the time arrived :1
# Enter of the text of the SMS :sfsd
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 2
# Message Count : 1
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 3
# Unread Indices : [0]
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 4
# Enter the Index of the message to retrieve : 0
# ('1', '1', 'sfsd')
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 5
# Enter the Index of the message to delete : 0
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 2
# Message Count : 0
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 3
# Unread Indices : []
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 1
# Enter from number :1
# Enter the time arrived :1
# Enter of the text of the SMS :1
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 1
# Enter from number :wedf
# Enter the time arrived :1sfd
# Enter of the text of the SMS :sdf
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 2
# Message Count : 2
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 6
# Choices:
# 1. Add Message
# 2. Print Message Count
# 3. List unread Indices
# 4. Print message
# 5. Delete Message
# 6. Clear
# Enter your choice: 2
# Message Count : 0