#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include <cstdlib>  // for rand() and srand() functions
#include <ctime>    // for time() function
using namespace std;
int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "           Welcome to the Guess the Number game!\n";
    cout << "I have selected a random number between 1 and 100. Try to guess it!\n";

    cout<<endl;
    do {
        // Prompt user for their guess
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Increment the number of attempts
        attempts++;

        // Provide feedback based on the user's guess
        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again by guessing a bigger number.\n";
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again by guessing a smaller number.\n";
        } else {
            cout<<endl;
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }

    } while (userGuess != randomNumber);

    return 0;
}
