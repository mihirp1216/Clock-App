/*
* This program will show 12 and 24 hour clock in their website.
* Author:  Mihir Patel
* Date: May 16, 2021
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
* This class has a public integers and also has function for
* handleTime, addSecond, addMinute, addHour, waitSecond, displayTime, displayMenu.
*/
// Time class
class Time
{
public:
    int hour12, hour24, min12, min24, sec12, sec24;
    // default constructor
    // Has two clock 12 hour format and 24 hour format.
    Time()
    {
        this->hour12 = 12;
        this->hour24 = 0;
        this->min12 = 0;
        this->min24 = 0;
        this->sec12 = 0;
        this->sec24 = 0;
    }

    /*
    * This function will handle time like it will check that second and minute not excced 60 and if they excced then hour increment.
    * parameter - int t as an check for two possibility
    * return - sec12, min12, hour12, sec24, min24, hour24 and it will add all variables everytime the function calls.
    */
    void handleTime(int t = 1)
    {
        if (t == 1) // if t = 1 then check for 12 hour format
        {
            if (sec12 / 60 > 0) // seconds is greater than 60 then it will add minute
            {
                sec12 %= 60;
                min12++;
            }
            if (min12 / 60 > 0) // minute is greater than 60 then it will add hour
            {
                min12 %= 60;
                hour12++;
            }
            if (hour12 / 12 > 0) // hour is greater than 12 then it will change to 1 again
            {
                hour12 %= 12;
                if (hour12 == 0)
                {
                    hour12 = 12;
                }
            }
        }
        if (t == 2) // if t = 1 then check for 24 hour format
        {
            if (sec24 / 60 > 0) // seconds is greater than 60 then it will add minute
            {
                sec24 %= 60;
                min24++;
            }
            if (min24 / 60 > 0) // minute is greater than 60 then it will add hour
            {
                min24 %= 60;
                hour24++;
            }
            if (hour24 / 24 > 0) // hour is greater than 24 then it will change to 1 again
            {
                hour24 %= 24;
                if (hour24 == 0)
                {
                    hour24 = 24;
                }
            }
        }
    }

    /*
    * This function will add second to 12 and 24 hour format when this function calls.
    * parameter - no parameter
    * return - increase a second to two format clock and also check that second not excced 60.
    */
    void addSecond()
    {
        sec12++;
        sec24++;
        handleTime(1);
        handleTime(2);
    }

    /*
    * This function will add 2 wait second to 12 and 24 hour format when this function calls.
    * parameter - no parameter
    * return - increase a second to two format clock and also check that second not excced 60.
    */
    void waitSecond()
    {
        sec12++;
        sec24++;
        handleTime(1);
        handleTime(2);
    }

    /*
    * This function will add minute to 12 and 24 hour format when this function calls.
    * parameter - no parameter
    * return - increase a minute to two format clock and also check that minute not excced 60.
    */
    void addMinute()
    {
        min12++;
        min24++;
        handleTime(1);
        handleTime(2);
    }

    /*
    * This function will add hour to 12 and 24 hour format when this function calls.
    * parameter - no parameter
    * return - increase a hour to two format clock and also check that second and minute not excced 60.
    */
    void addHour()
    {
        hour12++;
        hour24++;
        handleTime(1);
        handleTime(2);
    }

    /*
    * This function will display clock with functionality.
    * parameter - no parameter
    * return - 12 hour format and 24 hour format.
    */
    void displayTime()
    {
        cout << "************************** **************************\n";
        cout << "     * 12-Hour Clock *          * 24-Hour Clock *\n" << "     * ";
        cout << setw(2) << setfill('0') << hour12 << ":";
        cout << setw(2) << setfill('0') << min12 << ":";
        cout << setw(2) << setfill('0') << sec12 << " " << "     *" << "          * ";
        cout << setw(2) << setfill('0') << hour24 << ":";
        cout << setw(2) << setfill('0') << min24 << ":";
        cout << setw(2) << setfill('0') << sec24 << "      *\n";
        cout << "************************** **************************\n";
    }

    /*
    * This function will show user to choose option from menu to add hour, add minute, add second, exit program.
    * parameter - no parameter
    * return - it will return menu for user to choose option from menu.
    */
    void displayMenu()
    {
        cout << "-------------------------------\n";
        cout << "*  Choose options from menu   *\n";
        cout << "-------------------------------\n";
        cout << "*      1-Add One Hour         *\n";
        cout << "*      2-Add One Minute       *\n";
        cout << "*      3-Add One Second       *\n";
        cout << "*      4-Exit Program         *\n";
        cout << "-------------------------------\n";
    }
};



int main()
{
    // We wil use Time class here in main
    Time t;
    // Create a variables to use in while loop.
    int buttonOption, chooseOption, addOption, exitProgram = 1;

    // Using while loop
    while (exitProgram > 0)
    {
        //display clock when we run program
        t.displayTime();
        cout << "Press Button? (1.Yes or 2.No): " << endl; // Then prompt to user to select 1 for yes and 2 for no.
        cin >> buttonOption; // Ask user to select
        // User select 1 then this we use this if statement
        if (buttonOption == 1)
        {
            cout << "Do you want to exit? (1. Add Time or 2. Exit): " << endl; // Again prompt user to select 1 for add time or 2 for exit.
            cin >> chooseOption; // Ask user to select
            if (chooseOption == 1)
            {
                // if user select 1 then program shows a menu to select option
                t.displayMenu();
                cin >> addOption; // Ask user to select option from menu
                // using switch option to select case by the menu shows before
                switch (addOption)
                {
                    // case 1 add hour to both clock.
                case 1:
                    t.addHour();
                    break;
                    // case 2 add minute to both clock.
                case 2:
                    t.addMinute();
                    break;
                    // case 3 add second to both clock.
                case 3:
                    t.addSecond();
                    break;
                    // it will break when exitprogram variable is less than 0. 
                default:
                    exitProgram = -1;
                }
            }
            else if (chooseOption == 2) // if user choose option 2 then it will stop loop and break.
            {
                break;
            }
            else {
                cout << "Invaild input. Please try again." << endl; //prompt the user if user put invaild number.
            }
        }
        // if user choose option 2 then it will add second and also add wait second then it will break.
        else if (buttonOption == 2)
        {
            t.addSecond();
            t.waitSecond();
            break;
        }
        else {
            cout << "Invaild input. Please try again." << endl; //prompt the user if user put invaild number.
        }
    }
}



