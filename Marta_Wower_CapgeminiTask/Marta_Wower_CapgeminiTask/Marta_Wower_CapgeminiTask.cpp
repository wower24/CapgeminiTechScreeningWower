// Marta_Wower_CapgeminiTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Marta_Wower_CapgeminiTask.h"

int main()
{
    int number = 0;
    while (number != 4)
    {
        std::cout << "Hello, please choose what do you want to do:" << std::endl
            << "1 - add phone\n 2 - show a report\n 3 - delete phone\n 4 - quit\n";
        switch (number) {
        case 1: {
            addPhone();
            break;
        }
        case 2: {
            report();
        }
        case 3: {
            int deleteID = 0;
            std::cout << "Please provide an ID of the phone that should be deleted: ";
            std::cin >> deleteID;
            deletePhone(deleteID);
            std::cout << std::endl;
            break;
        }
        default: {
            std::cout << "Wrong number, try again\n";
            break;
        }
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
