#include <iostream>
#include <string>
#include <windows.h>
#include "TuringMachine.h"

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::string;

TuringMachine loadMachineFromFile(const string &filename);

int main()
{
    while (true)
    {
        Sleep(1000);
        cout << "Select a Turing Machine to run:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Palindrome\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";

        int choice;
        cin >> choice;
        string filepath;

        switch (choice)
        {
        case 1:
            cout << "\nYou selected Addition.\nEnter two numbers (1s) separated by a plus sign (e.g., 111+11):\n";
            filepath = "machines/add.tm";
            break;

        case 2:
            cout << "\nYou selected Subtraction.\nEnter two numbers separated by a minus sign (e.g., 1111-11):\n";
            filepath = "machines/subtract.tm";
            break;
        case 3:
            cout << "\nYou selected Multiplication.\nEnter two numbers separated by a '0' (e.g., 1110110):\n";
            filepath = "machines/multiply.tm";
            break;

        case 4:
            cout << "\nYou selected Division.\nEnter two numbers separated by a '0' (e.g., 1110110):\n";
            filepath = "machines/divide.tm";
            break;

        case 5:
            cout << "\nYou selected Palindrome Checker.\nEnter a binary string (0s and 1s) to check if it is a palindrome:\n";
            filepath = "machines/palindrome.tm";
            break;

        case 6:
            cout << "\nThank You!" << endl;
            return 0;
        default:
            cout << "\nInvalid choice.\n"
                 << endl;
            continue;
        }

        cout << "Enter input string for the Turing Machine: ";
        string input;
        cin >> input;

        try
        {
            TuringMachine tm = loadMachineFromFile(filepath);
            tm.setTape(input);
            cout << "Running Turing Machine from: " << filepath << endl;
            cout << "Initial tape: ";
            tm.printTape();
            tm.run();
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            return 1;
        }
    }
}
