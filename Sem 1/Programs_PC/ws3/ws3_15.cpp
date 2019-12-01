#include <iostream>
#include <stdlib.h>

int main()
{
    unsigned short Input;
    std::cout << "\nEnter the Input : ";
    std::cin >> Input;
    if (Input >= 100 && Input <= 999)
    {
        if (Input - ((Input % 10) + ((int)(Input / 100) * 100) == ((Input % 10) + (Input / 100))))
            std::cout << "\nThe Middle Digit is the sum of the other two digits";
        else
        {
            std::cout << "\nThe Middle Digit is not the sum of the other two digits";
        }
    }
    else
    {
        std::cout << "\nERROR!\nEnter a three digit number";
        exit(7);
    }
    std::cout << std::endl;
    return 0;
}