#include <iostream>
#include <iomanip>
#include <limits>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    double balance = 0;
    int choice = 0;


    do {
        std::cout << "Welcome to the banking system\n";
        std::cout << "Enter your choice:\n";
        std::cout << "-----------------------\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. exit\n";

        std::cin >> choice;
        
        
        switch (choice)
        {
        case 1: showBalance(balance);
            break;
        case 2: balance += deposit();
            showBalance(balance);
            break;
        case 3: balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4: std::cout << "Thanks for visiting\n";
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }while(choice != 4);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit() {
    double amount = 0;
    std::cout << "Enter amount to be deposited: $";
    std::cin >> amount;
    if(amount > 0) {
        return amount;
    }else{
        std::cout << "Invalid amount\n";
        return 0;
    }
}
double withdraw(double balance) {
    double amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;

    if (amount > balance) {
        std::cout << "Insufficient funds\n";
        return 0;
    } else if (amount <= 0) {
        std::cout << "Invalid amount\n";
        return 0;
    }else{
        return amount;
    }
}