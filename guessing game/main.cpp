#include <iostream>
#include "functions.h"


int main()
{
    std::cout << "*****Welcome to the number guessing game!*****" << std::endl;

    int max_attempts = 15;
    int attempts_taken = 0;
    int guess;
    int answer{generateRandomNumber()};
    
    while (attempts_taken != max_attempts)
    {
        guess = getGuess();
        attempts_taken++;
        if (guess == answer)
        {
            std::cout << "Correct!" << '\n';
            std::cout << "You took " << attempts_taken << " attempts to guess the number." << '\n';
            break;
        } else if (guess > answer)
        {
            std::cout << "Your guess is too HIGH." << '\n';
            std::cout << "You have " << (max_attempts - attempts_taken) << " left" << '\n';
        }else
        {
            std::cout << "Your guess is too LOW." << '\n';
            std::cout << "You have " << (max_attempts - attempts_taken) << " left" << '\n';
        }
        if (attempts_taken == max_attempts)
        {
            std::cout << "You have run out of attempts." << '\n';
            break;
        }
    }
    std::cout << "GAME END" << '\n';
    return 0;
}

