#include <iostream>
#include <random>

int getGuess()
{
    int guess{};
    
    std::cout << "Enter a guess between 1-100" << '\n';
    std::cin >> guess;
    return guess;

}

int generateRandomNumber()
{
    int answer{};
    // 1. Obtain a random seed from the hardware
    std::random_device rd;
    
    // 2. Initialize the Standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());
    
    // 3. Define the inclusive range [minimum, maximum]
    std::uniform_int_distribution<> distr(1, 100);
    
    // 4. Generate the random number
    int random_num = distr(gen);
    
    return random_num;
}
