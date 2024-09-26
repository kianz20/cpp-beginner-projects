#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits>
#include <fstream>
#include <string>

int main()
{
    while (true)
    {
        int n;
        std::cout << "\nWhat range of numbers do you want to play with?\n";
        std::cin >> n;

        srand(time(0));
        int answer = rand() % n;
        int guess;

        std::cout << "Start guessing!\n";

        while (answer != guess)
        {
            if (std::cin >> guess)
            {
                if (guess < 0 || guess > n)
                {
                    std::cout << "Out of range, pick between 0 and " << n << "\n";
                    continue;
                }
                if (answer > guess)
                {
                    std::cout << "Too low\n";
                }
                else if (guess > answer)
                {
                    std::cout << "Too high\n";
                }
            }
            else
            {
                std::cout << "\nThat isn't valid.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        std::cout << "You won! The answer was " << answer;
        std::cout << "\nEnter X to close, or any other button to play again";

        char input;
        std::cin >> input;
        if (input == 'X' || input == 'x')
        {
            break;
        }
    }
}