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

std::vector<std::string> getNames(std::vector<std::string> scores)
{
    std::vector<std::string> names;
    for (std::string i : scores)
    {
        if (!std::all_of(i.begin(), i.end(), ::isdigit) && !i.empty())
        {
            names.push_back(i);
        }
    }
    return names;
}

std::vector<int> printScoresOnly(std::vector<std::string> scores)
{
    std::vector<int> scoresReturn;
    for (std::string i : scores)
    {
        if (std::all_of(i.begin(), i.end(), ::isdigit) && !i.empty())
        {
            scores.push_back(i);
        }
    }
    return scoresReturn;
}

std::vector<std::string> addToScores(std::vector<std::string> scores, int score)
{
    std::string name;
    std::cout << "Enter your name";
    std::cin >> name;
    if (std::find(scores.begin(), scores.end(), name) != scores.end())
    {
        auto
    }
    else
    {
        scores.push_back(name);
        scores.push_back(std::to_string(score));
    }
    return scores;
}

int main()
{
    std::fstream highScores("highScore.txt", std::ios::in | std::ios::out);
    std::string scores;

    if (highScores.is_open())
    {
        while (highScores.good())
        {
            char ch = highScores.get();
            scores = scores + ch;
        }
    };
    highScores.clear();

    std::vector<std::string> scoreVector;
    boost::split(scoreVector, scores, boost::is_any_of(" \n"));

    // printScoresOnly(scoreVector);
    // printHighScores(scoreVector);

    while (true)
    {
        // addToScores(scoreVector);
    }
    highScores.close();
}