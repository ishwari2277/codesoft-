#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess : "; //take input
        cin >> userGuess;
        attempts++; // Increment the number of attempts
        
		// Provide feedback on the guess
        if (userGuess < secretNumber) {
            cout << "Too low! ";
        } else if (userGuess > secretNumber) {
            cout << "Too high! ";
        }

        // Additional hints
        if (abs(userGuess - secretNumber) >= 50) {
            cout << "You are very far away.\n";
        } else if (abs(userGuess - secretNumber) >= 30) {
            cout << "You are far away.\n";
        } else if (abs(userGuess - secretNumber) >= 10) {
            cout << "You are getting close.\n";
        } else {
            cout << "You are very close!\n";
        }


    } while (userGuess != secretNumber);
    cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
    return 0;
}

