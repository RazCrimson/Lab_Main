#include <iostream>

using namespace std;

class Donor
{
    string name, address;
    char sex, bloodgroup[3];
    int age, donorNumber;

public:
    Donor(string &cName, int &cNumber, int &cAge, string &cAddress, char &cSex, char cBlood[3])
    {
        name = cName;
        donorNumber = cNumber;
        age = cAge;
        address = cAddress;
        sex = toupper(cSex);
        bloodgroup[0] = toupper(cBlood[0]);
        bloodgroup[1] = cBlood[1];
        bloodgroup[2] = '\0';
    }

    void print()
    {
        cout << "Donor Name : " << name << "\nAge : "
             << "\nGender : " << sex << age << "\nBlood Group : " << bloodgroup << "\nNumber : " << donorNumber << "\nAddress : " << address;
    }

    void display(Donor *arr[], int &len, char blood[3])
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->bloodgroup[0] == blood[0] && arr[i]->bloodgroup[1] == blood[1])
                arr[i]->print();
        }
    }

    void display(Donor *arr[], int &len, int low, int high)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->age >= low && arr[i]->age <= high)
                arr[i]->print();
        }
    }

    void display(Donor *arr[], int &len, char blood[3], char cSex, int low, int high)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->age >= low && arr[i]->age <= high && arr[i]->bloodgroup[0] == blood[0] && arr[i]->sex == cSex)
                arr[i]->print();
        }
    }
};

int main()
{
    int n;
    cout << "Enter the no. of donors : ";
    cin >> n;
    if (n < 1)
    {
        cout << "Invalid Array Size";
        exit(0);
    }
    Donor *arr[n];
    for (int i = 0; i < n; i++)
    {
        string name, address;
        char sex, bloodgroup[3];
        int age, donorNumber;
        cout << "Enter the Donor's Name : ";
        getline(cin, name);
        cin.ignore();
        cout << "Enter the Donor's Age : ";
        cin >> age;
        cout << "Enter the Donor's Gender(M/F) : ";
        cin >> sex;
        cout << "Enter the Donor's Address : ";
        getline(cin, address);
        cin.ignore();
        cout << "Enter the Donor's Blood Group : ";
        cin >> bloodgroup;
        cout << "Enter the Donor's Number : ";
        cin >> donorNumber;
        static Donor a(name, donorNumber, age, address, sex, bloodgroup);
        arr[i] = &a;
    }
    // add menu creation
}