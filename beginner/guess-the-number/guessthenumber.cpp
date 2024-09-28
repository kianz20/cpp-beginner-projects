#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits>

int n;
int guess;
int answer;

std::string guessFeedback()
{
    if (guess < 0 || guess > n)
    {
        return "Out of range, pick between 0 and " + std::to_string(n) + "\n";
    }
    if (answer > guess)
    {
        return "Too low\n";
    }
    else if (guess > answer)
    {
        return "Too high\n";
    }
    else
    {
        return "You won! The answer was " + std::to_string(answer);
    }
}

int main()
{
    while (true)
    {
        std::cout << "\nWhat range of numbers do you want to play with?\n";
        std::cin >> n;

        srand(time(0));
        answer = rand() % n;

        std::cout << "Start guessing!\n";

        while (answer != guess)
        {
            if (std::cin >> guess)
            {
                std::cout << guessFeedback();
            }
            else
            {
                std::cout << "\nThat isn't valid.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        std::cout << "\nEnter X to close, or any other button to play again";

        char input;
        std::cin >> input;
        if (input == 'X' || input == 'x')
        {
            break;
        }
    }
}