#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

static const std::string word = "alpha";
static constexpr int maxHealth = 6;

int main()
{
    std::unordered_map<int, std::pair<char, bool>> wordMap;
    for (int i = 0; i < word.length(); i++)
    {
        wordMap[i] = {word[i], false};
    }

    std::cout << "The word contains " << word.length() << " letters." << std::endl;

    std::string input;
    bool dead = false;
    int health = maxHealth;
    int trialCount = 0;
    while (!dead)
    {
        bool allGuessed = true;
        for (auto& [_, letterPair] : wordMap)
        {
            auto& [letter, guessed] = letterPair;
            std::cout << (guessed ? letter : '*');
            if (!guessed)
            {
                allGuessed = false;
            }
        }
        std::cout << std::endl;
        if (allGuessed)
        {
            std::cout << "You got the word right!!!" << std::endl;
            goto FINISHED;
        }

        std::cout << "______________________________" << std::endl;
        std::cout << "Trial #" << trialCount << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::getline(std::cin, input);

        switch (input.length())
        {
            case 1:
            {
                char guess = input[0];
                bool guessed = false;
                for (int i = 0; i < word.length(); i++)
                {
                    if (guess == word[i])
                    {
                        wordMap[i].second = true;
                        std::cout << "You got this right" << std::endl;
                        guessed = true;
                    }
                }
                if (!guessed)
                {
                    health--;
                    std::cout << "It was wrong" << std::endl;
                }
                break;
            }
            case 0:
            {
                std::cout << "Please enter your guess" << std::endl;
                continue;
            }
            default:
            {
                if (input == word)
                {
                    std::cout << "You got the word right!!!" << std::endl;
                    goto FINISHED;
                }
                else
                {
                    std::cout << "Incorrect" << std::endl;
                    health--;
                }
                break;
            }
        }

        trialCount++;
        if (health == 0)
        {
            dead = true;
            std::cout << "FAIL!!!" <<std::endl;
        }
    }
    FINISHED:

    return 0;
}
