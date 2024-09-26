#include <iostream>
#include <limits>

char board[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
char turn = 'Y';
int input;

void printBoard()
{
    for (int i = 0; i < 9; i += 3)
    {
        std::cout << " \n ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << " " << board[i + j];
            if (j < 2)
            {
                std::cout << " | ";
            }
        }
        if (i < 6)
        {
            std::cout << "\n ---|----|---";
        }
        else
        {
            std::cout << " \n ";
        }
    }
}

bool checkWin()
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] != '0')
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] != '0')
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] != '0')
    {
        return true;
    }

    if (board[2] == board[4] && board[0] == board[6] && board[0] != '0')
    {
        return true;
    }

    return false;
}

int main()
{
    while (!checkWin())
    {
        int input;
        if (turn == 'X')
        {
            turn = 'Y';
        }
        else
        {
            turn = 'X';
        }
        std::cout << "\n"
                  << turn << "\'s turn! Enter a number between 1 and 9";
        printBoard();
        if (std::cin >> input)
        {

            if (input < 1 || input > 9)
            {
                std::cout << "\nThat isn't valid.\n";
                continue;
            }
            if (board[input - 1] != '0')
            {
                std::cout << turn << "\nSpace taken.\n";
                continue;
            }
            board[input - 1] = turn;
        }
        else
        {
            std::cout << "\nThat isn't valid.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Game over, " << turn << " wins!\n";
    printBoard();
    return 0;
}
