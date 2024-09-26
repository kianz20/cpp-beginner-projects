#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <cctype>

void printHighScores(std::vector<std::string> scores)
{
    for (std::string i : scores)
    {
        std::cout << i << ' ';
        if (std::all_of(i.begin(), i.end(), ::isdigit) && !i.empty())
        {
            std::cout << '\n';
        }
    }
}

void printScoresOnly(std::vector<std::string> scores)
{
    for (std::string i : scores)
    {
        if (std::all_of(i.begin(), i.end(), ::isdigit) && !i.empty())
        {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
}

int main()
{
    std::ifstream highScores("highScore.txt");
    std::string scores;

    if (highScores.is_open())
    {
        while (highScores.good())
        {
            char ch = highScores.get();
            scores = scores + ch;
        }
    }
    std::vector<std::string> scoreVector;
    boost::split(scoreVector, scores, boost::is_any_of(" \n"));

    printScoresOnly(scoreVector);
    printHighScores(scoreVector);
}