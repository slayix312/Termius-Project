#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>

// Function declarations
void displayMenu();
void greetUser();
void calculator();
void stringUtilities();
void fileOperations();
void displayVector();
void clearInputBuffer();

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << "   Welcome to Termius Project!" << std::endl;
    std::cout << "   A Comprehensive C++ Sample Program" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::endl;

    greetUser();

    bool running = true;
    while (running) {
        displayMenu();
        
        int choice;
        std::cout << "Enter your choice: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }
        clearInputBuffer();

        std::cout << std::endl;

        switch (choice) {
            case 1:
                calculator();
                break;
            case 2:
                stringUtilities();
                break;
            case 3:
                fileOperations();
                break;
            case 4:
                displayVector();
                break;
            case 5:
                std::cout << "Thank you for using Termius Project!" << std::endl;
                std::cout << "Goodbye!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice! Please select 1-5." << std::endl;
        }

        if (running) {
            std::cout << std::endl;
        }
    }

    return 0;
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Calculator" << std::endl;
    std::cout << "2. String Utilities" << std::endl;
    std::cout << "3. File Operations" << std::endl;
    std::cout << "4. Vector Demo" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

void greetUser() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        name = "Guest";
    }

    std::cout << std::endl;
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Let's explore some C++ features together." << std::endl;
    std::cout << std::endl;
}

void calculator() {
    std::cout << "=== Calculator ===" << std::endl;
    std::cout << "Available operations: +, -, *, /" << std::endl;
    
    double num1, num2;
    char operation;

    std::cout << "Enter first number: ";
    if (!(std::cin >> num1)) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Error: Invalid number!" << std::endl;
        return;
    }

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    if (!(std::cin >> num2)) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Error: Invalid number!" << std::endl;
        return;
    }
    clearInputBuffer();

    double result;
    bool valid = true;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero!" << std::endl;
                valid = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Invalid operation!" << std::endl;
            valid = false;
    }

    if (valid) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }
}

void stringUtilities() {
    std::cout << "=== String Utilities ===" << std::endl;
    std::cout << "Enter a string: ";
    
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "No string entered!" << std::endl;
        return;
    }

    // Display original
    std::cout << "\nOriginal: " << input << std::endl;

    // Length
    std::cout << "Length: " << input.length() << " characters" << std::endl;

    // Uppercase
    std::string uppercase = input;
    std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);
    std::cout << "Uppercase: " << uppercase << std::endl;

    // Lowercase
    std::string lowercase = input;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    std::cout << "Lowercase: " << lowercase << std::endl;

    // Reverse
    std::string reversed = input;
    std::reverse(reversed.begin(), reversed.end());
    std::cout << "Reversed: " << reversed << std::endl;

    // Count vowels
    int vowelCount = 0;
    for (char c : input) {
        char lower = std::tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            vowelCount++;
        }
    }
    std::cout << "Vowel count: " << vowelCount << std::endl;
}

void fileOperations() {
    std::cout << "=== File Operations ===" << std::endl;
    std::cout << "Enter text to save to file: ";
    
    std::string text;
    std::getline(std::cin, text);

    if (text.empty()) {
        std::cout << "No text entered!" << std::endl;
        return;
    }

    // Write to file
    std::string filename = "termius_output.txt";
    std::ofstream outFile(filename);
    
    if (!outFile) {
        std::cout << "Error: Could not create file!" << std::endl;
        return;
    }

    outFile << "Termius Project - File Output" << std::endl;
    outFile << "================================" << std::endl;
    outFile << text << std::endl;
    outFile.close();

    std::cout << "Text saved to '" << filename << "'" << std::endl;

    // Read from file
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Error: Could not read file!" << std::endl;
        return;
    }

    std::cout << "\nFile contents:" << std::endl;
    std::cout << "---" << std::endl;
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "---" << std::endl;
    inFile.close();
}

void displayVector() {
    std::cout << "=== Vector Demo ===" << std::endl;
    std::cout << "This demonstrates C++ vectors (dynamic arrays)." << std::endl;
    std::cout << std::endl;

    // Create and populate vector
    std::vector<int> numbers;
    std::cout << "Enter numbers (enter 0 to finish):" << std::endl;

    int num;
    while (true) {
        std::cout << "Number: ";
        if (!(std::cin >> num)) {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
        
        if (num == 0) {
            break;
        }
        
        numbers.push_back(num);
    }
    clearInputBuffer();

    if (numbers.empty()) {
        std::cout << "No numbers entered!" << std::endl;
        return;
    }

    // Display vector
    std::cout << "\nYour numbers: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    // Statistics
    int sum = 0;
    int min = numbers[0];
    int max = numbers[0];

    for (int n : numbers) {
        sum += n;
        if (n < min) min = n;
        if (n > max) max = n;
    }

    double average = static_cast<double>(sum) / numbers.size();

    std::cout << "Count: " << numbers.size() << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average: " << average << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    // Sort
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    std::cout << "Sorted: ";
    for (size_t i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i];
        if (i < sorted.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}
