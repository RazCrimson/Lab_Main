'''
Program for Set 3 for Final Lab test of Python Lab for testing the class

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


# Main Function
if __name__ == '__main__':
    try:
        my_inbox = SMS_Store()

        # Checking for empty mailbox
        assert my_inbox.message_count()  == 0
        assert my_inbox.get_unread_indexes()  == []

        
        # Adding a mail and then checking
        my_inbox.add_new_arrival(1,1,"Some text")

        assert my_inbox.get_unread_indexes() == [0]
        assert my_inbox.get_message(0) == (1, 1, "Some text")
        assert my_inbox.get_unread_indexes() == []
        assert my_inbox.message_count() == 1

        # Deleteing that message and checking
        my_inbox.delete(0)
        assert my_inbox.get_message(0) == None
        assert my_inbox.message_count() == 0

        # Adding few mails
        my_inbox.add_new_arrival(1,1,"Some text")
        my_inbox.add_new_arrival(2,2,"Some text1")
        my_inbox.add_new_arrival(2,2,"Some text2")

        assert my_inbox.message_count() == 3
        my_inbox.clear()
        assert my_inbox.message_count() == 0
        print('All Test cases passed')
    except Exception as e:
        print('Test cases failed!')