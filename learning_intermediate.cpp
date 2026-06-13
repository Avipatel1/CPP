#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cstring>

using namespace std;

// ============================================================================
// SECTION 1: POINTERS AND DYNAMIC MEMORY
// ============================================================================

void demonstratePointers() {
    cout << "\n--- POINTERS: Variables that store memory addresses ---" << endl;

    int x = 42;
    int* ptr = &x;  // Pointer to x (& = address of operator)

    cout << "x = " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "ptr points to: " << *ptr << endl;  // * = dereference operator
    cout << "ptr stores address: " << ptr << endl;

    // DYNAMIC MEMORY - Allocating memory at runtime
    cout << "\n--- DYNAMIC MEMORY with new and delete ---" << endl;

    int* dynamicInt = new int(100);  // Allocate on heap
    cout << "Dynamic int value: " << *dynamicInt << endl;
    delete dynamicInt;  // MUST free memory when done
    dynamicInt = nullptr;  // Good practice: set to nullptr after delete

    // Dynamic arrays
    int* arr = new int[5]{10, 20, 30, 40, 50};
    cout << "Dynamic array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;  // Use delete[] for arrays

    // SMART POINTERS - Automatic memory management
    cout << "\n--- SMART POINTERS (automatic cleanup) ---" << endl;
    {
        unique_ptr<int> smartInt(new int(200));
        cout << "Smart pointer value: " << *smartInt << endl;
        // Memory automatically freed when smartInt goes out of scope
    }
}

// ============================================================================
// SECTION 2: CONST AND STATIC
// ============================================================================

class StaticDemo {
private:
    static int objectCount;  // Shared by all instances
    int id;

public:
    StaticDemo() {
        objectCount++;
        id = objectCount;
    }

    static int getObjectCount() {
        return objectCount;
    }

    int getId() const {  // const member function (doesn't modify object)
        return id;
    }
};

int StaticDemo::objectCount = 0;  // Initialize static member

void demonstrateConstStatic() {
    cout << "\n--- CONST and STATIC ---" << endl;

    const int MAX_SIZE = 100;  // Constant - cannot be changed
    cout << "Max size: " << MAX_SIZE << endl;

    StaticDemo obj1, obj2, obj3;
    cout << "Created 3 objects. Total: " << StaticDemo::getObjectCount() << endl;
}

// ============================================================================
// SECTION 3: INHERITANCE AND POLYMORPHISM
// ============================================================================

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual void makeSound() {  // virtual = can be overridden
        cout << name << " makes a sound" << endl;
    }

    virtual void info() const {
        cout << "Animal: " << name << endl;
    }

    virtual ~Animal() {}  // Virtual destructor for proper cleanup
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    Dog(string n) : Animal(n) {}

    void makeSound() override {  // override specifier (C++11)
        cout << name << " barks: Woof! Woof!" << endl;
    }

    void info() const override {
        cout << "Dog: " << name << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void makeSound() override {
        cout << name << " meows: Meow~ Meow~" << endl;
    }

    void info() const override {
        cout << "Cat: " << name << endl;
    }
};

void demonstratePolymorphism() {
    cout << "\n--- INHERITANCE AND POLYMORPHISM ---" << endl;

    vector<Animal*> animals;  // Pointer to base class
    animals.push_back(new Dog("Rex"));
    animals.push_back(new Cat("Whiskers"));
    animals.push_back(new Dog("Buddy"));

    cout << "Polymorphic calls:" << endl;
    for (Animal* animal : animals) {
        animal->info();
        animal->makeSound();
    }

    // Cleanup
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

// ============================================================================
// SECTION 4: TEMPLATES - Generic Programming
// ============================================================================

// Function template - works with any type
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class template
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(T value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw runtime_error("Stack is empty!");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

void demonstrateTemplates() {
    cout << "\n--- TEMPLATES (Generic Programming) ---" << endl;

    cout << "Max of ints: " << findMax(10, 25) << endl;
    cout << "Max of doubles: " << findMax(3.14, 2.71) << endl;
    cout << "Max of strings: " << findMax(string("Apple"), string("Zebra")) << endl;

    cout << "\nUsing Stack template:" << endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    while (!intStack.isEmpty()) {
        cout << "Popped: " << intStack.pop() << endl;
    }
}

// ============================================================================
// SECTION 5: STL CONTAINERS
// ============================================================================

void demonstrateSTL() {
    cout << "\n--- STL CONTAINERS ---" << endl;

    // VECTOR - dynamic array
    cout << "\nVector:" << endl;
    vector<int> vec = {5, 2, 8, 1, 9};
    vec.push_back(3);
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // MAP - key-value pairs (like dictionary)
    cout << "\nMap (dictionary):" << endl;
    map<string, int> grades;
    grades["Alice"] = 95;
    grades["Bob"] = 87;
    grades["Charlie"] = 92;

    for (auto& pair : grades) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // SET - unique values only
    cout << "\nSet (unique values):" << endl;
    set<int> uniqueNumbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    cout << "Unique numbers: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
}

// ============================================================================
// SECTION 6: EXCEPTION HANDLING
// ============================================================================

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial) : balance(initial) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Insufficient funds!");
        }
        if (amount <= 0) {
            throw invalid_argument("Amount must be positive!");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

void demonstrateExceptions() {
    cout << "\n--- EXCEPTION HANDLING ---" << endl;

    BankAccount account(1000);

    try {
        cout << "Initial balance: $" << account.getBalance() << endl;
        account.withdraw(300);
        cout << "After withdrawal: $" << account.getBalance() << endl;
        account.withdraw(900);  // This will throw
    } catch (const runtime_error& e) {
        cout << "Runtime error caught: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Invalid argument caught: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Generic exception caught: " << e.what() << endl;
    }
}

// ============================================================================
// SECTION 7: OPERATOR OVERLOADING
// ============================================================================

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return os;
}

void demonstrateOperatorOverloading() {
    cout << "\n--- OPERATOR OVERLOADING ---" << endl;

    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
}

// ============================================================================
// SECTION 8: FILE I/O
// ============================================================================

void demonstrateFileIO() {
    cout << "\n--- FILE I/O OPERATIONS ---" << endl;

    // Writing to file
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << "Learning C++ intermediate concepts\n";
        outFile << "File I/O is important\n";
        outFile << "Handle errors properly\n";
        outFile.close();
        cout << "File written successfully" << endl;
    }

    // Reading from file
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string line;
        cout << "File contents:" << endl;
        while (getline(inFile, line)) {
            cout << "  " << line << endl;
        }
        inFile.close();
    } else {
        cout << "Could not read file" << endl;
    }
}

// ============================================================================
// SECTION 9: MOVE SEMANTICS (Brief Introduction)
// ============================================================================

class Resource {
private:
    int* data;
    size_t size;

public:
    Resource(size_t s) : size(s) {
        data = new int[s];
        cout << "Resource created" << endl;
    }

    ~Resource() {
        delete[] data;
        cout << "Resource destroyed" << endl;
    }

    // Move constructor (C++11)
    Resource(Resource&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        cout << "Resource moved (not copied)" << endl;
    }

    // Copy constructor (deleted for this example)
    Resource(const Resource&) = delete;
};

void demonstrateMoveSemantics() {
    cout << "\n--- MOVE SEMANTICS (C++11) ---" << endl;

    {
        Resource res(10);
        Resource moved = move(res);  // Move instead of copy
    }

    cout << "Scope exited" << endl;
}

// ============================================================================
// SECTION 10: FUNCTION POINTERS AND CALLBACKS
// ============================================================================

void displayNumber(int n) {
    cout << "Number: " << n << endl;
}

void doubleNumber(int n) {
    cout << "Doubled: " << (n * 2) << endl;
}

void applyFunction(int value, void (*func)(int)) {
    func(value);  // Call the function pointer
}

void demonstrateFunctionPointers() {
    cout << "\n--- FUNCTION POINTERS ---" << endl;

    void (*funcPtr)(int) = displayNumber;  // Function pointer

    cout << "Calling through pointer:" << endl;
    funcPtr(42);

    funcPtr = doubleNumber;
    funcPtr(21);

    cout << "\nUsing callback pattern:" << endl;
    applyFunction(10, displayNumber);
    applyFunction(10, doubleNumber);
}

// ============================================================================
// MAIN PROGRAM
// ============================================================================

int main() {
    cout << "========================================" << endl;
    cout << "  C++ INTERMEDIATE LEARNING PROGRAM" << endl;
    cout << "========================================" << endl;

    demonstratePointers();
    demonstrateConstStatic();
    demonstratePolymorphism();
    demonstrateTemplates();
    demonstrateSTL();
    demonstrateExceptions();
    demonstrateOperatorOverloading();
    demonstrateFileIO();
    demonstrateMoveSemantics();
    demonstrateFunctionPointers();

    cout << "\n========================================" << endl;
    cout << "  All sections completed!" << endl;
    cout << "========================================" << endl;

    return 0;
}
