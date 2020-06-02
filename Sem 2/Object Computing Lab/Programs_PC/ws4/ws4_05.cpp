#include<iostream>
using namespace std;

class SoccerPlayer
{
    int jersyNo, noOfGoals, noOfAssists;
    public:
        bool operator > (SoccerPlayer&);
        SoccerPlayer& operator = (const SoccerPlayer&);
        friend istream& operator >> (istream&, SoccerPlayer&);
        friend ostream& operator << (ostream&, const SoccerPlayer&);
};

bool SoccerPlayer::operator > (SoccerPlayer &player)
{
    if(noOfGoals + noOfAssists > player.noOfGoals + player.noOfAssists)
        return true;
    else
        return false;
}

SoccerPlayer& SoccerPlayer::operator = (const SoccerPlayer &player)
{
    jersyNo = player.jersyNo;
    noOfGoals = player.noOfGoals;
    noOfAssists = player.noOfAssists;
    return *this;
}

istream& operator >> (istream &in, SoccerPlayer &player)
{
    in.sync();
    cout << "Enter the Jersy Number: ";
    in >> player.jersyNo;
    cout << "Enter the number of goals: ";
    in >> player.noOfGoals;
    cout << "Enter the number of assists: ";
    in >> player.noOfAssists;
    return in;
}

ostream& operator << (ostream &out, const SoccerPlayer  &player)
{
    out << "Jersy Number: " << player.jersyNo << endl;
    out << "Number of goals: " << player.noOfGoals << endl;
    out << "Number of assistes: " << player.noOfAssists << endl;
    return out;
};

int main()
{
    SoccerPlayer players[11];
    cout << "Enter the detais of SoccerPlayers: \n";
    for(int i = 0; i < 11; i++)
    {
        cout << "Enter the details of player "<< i+1 <<endl;
        cin >> players[i];
    }
    SoccerPlayer large = players[0];
    for(int i = 1; i<11 ; i++)
    {
        if(players[i] > large)
            players[i] = large;
    }
    cout << large;
}