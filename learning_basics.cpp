#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ============================================================================
// SECTION 1: FUNCTIONS - Reusable blocks of code
// ============================================================================

// A function that takes no parameters and returns nothing
void sayHello() {
    cout << "Hello, C++ beginner!" << endl;
}

// A function that takes parameters and returns a value
int add(int a, int b) {
    return a + b;
}

// Function that demonstrates pass by value and pass by reference
void modifyByValue(int x) {
    x = 100;  // Only changes the local copy
}

void modifyByReference(int& x) {
    x = 100;  // Changes the original variable
}

// ============================================================================
// SECTION 2: CLASSES AND OBJECTS - Creating custom data types
// ============================================================================

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor - called when creating an object
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Member functions (methods)
    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    void printDimensions() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

// ============================================================================
// SECTION 3: LOOPS - Repeating code
// ============================================================================

void demonstrateLoops() {
    cout << "\n--- FOR LOOP (counting from 1 to 5) ---" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Count: " << i << endl;
    }

    cout << "\n--- WHILE LOOP (countdown from 5) ---" << endl;
    int count = 5;
    while (count > 0) {
        cout << "Countdown: " << count << endl;
        count--;  // Decrement count by 1
    }

    cout << "\n--- LOOPING THROUGH A VECTOR ---" << endl;
    vector<string> fruits = {"Apple", "Banana", "Cherry"};
    for (int i = 0; i < fruits.size(); i++) {
        cout << "Fruit " << i << ": " << fruits[i] << endl;
    }
}

// ============================================================================
// SECTION 4: CONDITIONALS - Making decisions
// ============================================================================

void checkGrade(int score) {
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: F" << endl;
    }
}

// ============================================================================
// SECTION 5: ARRAYS AND VECTORS - Collecting multiple values
// ============================================================================

void demonstrateCollections() {
    cout << "\n--- ARRAYS (fixed size) ---" << endl;
    int scores[3] = {85, 90, 88};
    for (int i = 0; i < 3; i++) {
        cout << "Score " << i << ": " << scores[i] << endl;
    }

    cout << "\n--- VECTORS (dynamic size) ---" << endl;
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (int num : numbers) {  // Enhanced for loop
        cout << "Number: " << num << endl;
    }
}

// ============================================================================
// MAIN PROGRAM - Where execution starts
// ============================================================================

int main() {
    cout << "=====================================" << endl;
    cout << "  C++ BEGINNER LEARNING PROGRAM" << endl;
    cout << "=====================================" << endl;

    // FUNCTIONS
    cout << "\n[SECTION 1: FUNCTIONS]" << endl;
    sayHello();

    int result = add(5, 3);
    cout << "5 + 3 = " << result << endl;

    int number = 42;
    cout << "Original number: " << number << endl;
    modifyByValue(number);
    cout << "After modifyByValue: " << number << " (unchanged)" << endl;
    modifyByReference(number);
    cout << "After modifyByReference: " << number << " (changed!)" << endl;

    // VARIABLES AND DATA TYPES
    cout << "\n[SECTION 2: VARIABLES AND DATA TYPES]" << endl;
    int age = 20;                          // Integer
    double height = 5.9;                   // Decimal number
    char initial = 'J';                    // Single character
    bool isStudent = true;                 // True or false
    string name = "Alex";                  // Text

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " feet" << endl;
    cout << "Initial: " << initial << endl;
    cout << "Is student: " << (isStudent ? "Yes" : "No") << endl;

    // CONDITIONALS
    cout << "\n[SECTION 3: CONDITIONALS]" << endl;
    cout << "Checking grade for score 85:" << endl;
    checkGrade(85);

    // LOOPS
    cout << "\n[SECTION 4: LOOPS]" << endl;
    demonstrateLoops();

    // ARRAYS AND VECTORS
    cout << "\n[SECTION 5: ARRAYS AND VECTORS]" << endl;
    demonstrateCollections();

    // CLASSES AND OBJECTS
    cout << "\n[SECTION 6: CLASSES AND OBJECTS]" << endl;
    Rectangle rect(5.0, 3.0);
    rect.printDimensions();
    cout << "Area: " << rect.getArea() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;

    // MATH OPERATIONS
    cout << "\n[SECTION 7: MATH OPERATIONS]" << endl;
    int a = 10, b = 3;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
    cout << a << " % " << b << " = " << (a % b) << " (remainder)" << endl;
    cout << "Square root of 16 = " << sqrt(16) << endl;

    // STRING OPERATIONS
    cout << "\n[SECTION 8: WORKING WITH STRINGS]" << endl;
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;  // String concatenation
    cout << "Full name: " << fullName << endl;
    cout << "Name length: " << fullName.length() << " characters" << endl;

    cout << "\n=====================================" << endl;
    cout << "  Program completed successfully!" << endl;
    cout << "=====================================" << endl;

    return 0;  // Return 0 to indicate successful execution
}
