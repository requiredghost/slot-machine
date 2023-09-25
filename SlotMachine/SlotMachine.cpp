#include <iostream>
#include <random>
using namespace std;

int chipscount = 2000;
void play();
void credits();
void exit();




int main()
{

    //menu variable
    int menu_option = 3;


    //menu
    cout << "\nPlayer's chips: " << chipscount << " \n" << endl;
    cout << "1) Play Slots" << endl;
    cout << "2) Credits" << endl;
    cout << "3) Quit \n" << endl;

    //menu option
    cout << "Enter: ";

    //option picker input
    cin >> menu_option;

    //switch statement for the selection
    switch (menu_option) {
    case 1:
        play();
    case 2:
        credits();
    case 3:
        exit(0);
    default: 
        std::cout << "\nInvalid input!\n" << std::endl;
        return main();
    }

    return 0;
}


//slot machine
void play()
{
    std::cout << "Enter your bet: ";

    int bet = 0;
    while (true)
    {
        std::cin >> bet;

        if (bet <= chipscount && bet >= 1)
            break;
        else
            std::cout << "\nInvalid input!" << std::endl;
            std::cout << "Enter your bet: ";


    }
    chipscount -= bet;
    // 2 3 4 5 6 7
    int num1 = 2 + rand() % 6;
    int num2 = 2 + rand() % 6;
    int num3 = 2 + rand() % 6;

    std::cout << num1 << " " << num2 << " " << num3 << std::endl;

    int returns = 0;
    if (num1 == num2 && num2 == num3)
    {
        returns = bet * ((num1 == 7) ? 10 : 5);
    }
    else if (num1 == num2 || num2 == num3 || num3 == num1) {
        returns = bet * 3;
    }
    if (chipscount == 0) {
        std::cout << "\nGame over! You have " << chipscount << " chips left!";
        exit(0);
    }
    if (returns != 0)
        std::cout << "You won $" << returns << "!" << std::endl;
    else
        std::cout << "You lost..." << std::endl;

    chipscount += returns;
    main();
}

//credits
void credits()
{
    cout << "\nMade by Ralsei, ralzei on GitHub\n";
    main();
}

