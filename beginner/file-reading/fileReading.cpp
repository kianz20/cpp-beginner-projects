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

std::vector<std::string> addToScores(std::vector<std::string> &scores, int score)
{
    std::string name;
    std::cout << "Enter your name";
    std::cin >> name;
    auto it = std::find(scores.begin(), scores.end(), name);
    if (it != scores.end())
    {
        std::cout << "Found: " << *it << std::endl;
        auto foundScore = std::next(it);
        if (score > std::stoi(*foundScore))
        {
            std::cout << "Update" << *foundScore << " score to " << score;
            *foundScore = std::to_string(score);
        }
        else
        {
            std::cout << "Your score " << score << " is less than existing highscore " << *foundScore;
        }
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

    std::vector<std::string> scoreVector;
    boost::split(scoreVector, scores, boost::is_any_of(" \n"));

    addToScores(scoreVector, 33);

    highScores.clear();
    highScores.seekp(0);

    for (size_t i = 0; i < scoreVector.size(); i += 2)
    {
        highScores << scoreVector[i] << " " << scoreVector[i + 1] << "\n";
    }

    highScores.close();

    for (std::string score : scoreVector)
    {
        std::cout << "\n"
                  << score;
    }

    highScores.close();
}