#include <iostream>

int main() {
    std::string questions[] = {
        "1. What year was C++ created?",
        "2. Who invented C++?",
        "3. What is the predecessor of C++?",
        "4. Is the Earth flat?"
    };

    std::string options[][4] = {
        {"a) 1980", "b) 1983", "c) 1985", "d) 1990"},
        {"a) Bjarne Stroustrup", "b) James Gosling", "c) Guido van Rossum", "d) Dennis Ritchie"},
        {"a) C", "b) Java", "c) Python", "d) Ruby"},
        {"a) Yes", "b) No", "c) Maybe", "d) I don't know"}
    };

    char answerKey[] = {'c', 'a', 'a', 'b'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score=0;

    for(int i=0; i<size; i++) {
        std::cout << "------------------------\n";
        std::cout << questions[i] << '\n';
        std::cout << "------------------------\n";

        for(int j=0; j<sizeof(options[i])/sizeof(options[i][0]); j++) {
            std::cout << options[i][j] << '\n';
        }

        std::cin >> guess;
        guess = tolower(guess);
        if(guess == answerKey[i]) {
            std::cout << "Correct!\n";
            score++;
        } else {
            std::cout << "Wrong! The correct answer is: " << answerKey[i] << '\n';
        }
    }
    std::cout << "--------RESULTS---------\n";
    std::cout << "Your final score is: " << score << "/" << size << '\n';
    std::cout << "Percentage: " << (score/(double)size)*100 << "%\n";
    std::cout << "------------------------\n";
    return 0;
}