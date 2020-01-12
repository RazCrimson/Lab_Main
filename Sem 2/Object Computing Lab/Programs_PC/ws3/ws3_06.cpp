#include <iostream>
#include <ctime>

using namespace std;

int counter = 0;

class Message
{

    string recipient, sender, messageText;
    time_t messageTime;

public:
    Message(string &, string &);
    ~Message();
    void printMessage();
    int instances();
};

Message::Message(string &qRecipient, string &qSender)
{
    char ch;
    recipient = qRecipient;
    sender = qSender;
    messageTime = time(0);
    cout << "Enter the message content : ";
    cin >> ch;
    while (ch != 27)
    {
        messageText += ch;
        cin >> ch;
    }
    counter +=1;
}

Message::~Message()
{
    counter -= 1;
}

void Message::printMessage()
{
    cout << messageText;
}

int Message::instances()
{
    return counter;
}