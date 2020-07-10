#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

string words[10] = {"pineapple", "lettuce", "orangutan", "lightbulb", "copper", "ambulance", "truck", "soda", "water", "chicken"}; 
int const maxStrikes = 8;
int strikes = 0;
int main()
{
    srand((unsigned int)time(NULL));
    std::string str = words[rand() % 10];
    cout <<"The word is " << str.length() << " characters long. Guess a letter. \n";
    std::vector<string> characters (str.length()); //Vector representing the characters in the random word.
    for(int i = 0; i < str.length(); i++)
    {
        characters[i] = "-";
    }
    while(std::find(characters.begin(), characters.end(), "-") != characters.end() && strikes < maxStrikes) // vector does not contain "-" and there are guesses left.
    {
        char letterGuess;
        cin >> letterGuess;
        if(str.find_first_of(letterGuess) != string::npos) //Test to see if character is in random word. 
        {
            for(int i = 0; i < str.length(); i++)
            {
                if(letterGuess == str.at(i)) // Guess is at character. 
                {
                    characters[i] = letterGuess;
                }
                cout << characters[i] << " ";
            }
            cout << "\nCorrect! Guess another letter.\n";
        }
        else
        {
            strikes ++;
            cout << "Wrong! You have " << maxStrikes - strikes << " guesses left. \n";
            for(string letters: characters)
            {
                cout << letters << " ";
            }
            cout << "\n";
        }
        
    }
    if(strikes == maxStrikes)
    {
        cout << "You lose! The word was " << str;
    }
    else
    {
        cout << "You Win!";
    }
}



