#include <iostream>

using namespace std;

int main() {
    double number1, number2, result;
    int operation;
	char c;
    cout << "Simple Calculator\n";
    cout << "Enter first number: "<<endl;
    cin >> number1;

    cout << "Enter second number: "<<endl;
    cin >> number2;
    
	do{
    cout << "***Choose an operation from *** "<<endl;
    cout << "1.Addition"<<endl;
    cout << "2.Subtraction "<<endl;
    cout << "3.Multiplication"<<endl;
    cout << "4.Division"<<endl;
    cin >> operation;

    switch (operation) {
        case 1:
            result = number1 + number2;
            cout << "Result: " << number1 << " + " << number2 << " = " << result << endl;
            break;
        case 2:
            result = number1 - number2;
            cout << "Result: " << number1 << " - " << number2 << " = " << result << endl;
            break;
        case 3:
            result = number1 * number2;
            cout << "Result: " << number1 << " * " << number2 << " = " << result << endl;
            break;
        case 4:
            if (number2 != 0) {
                result = number1 / number2;
                cout << "Result: " << number1 << " / " << number2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Error: Invalid operation.\n";
    }
    cout<<"DO YOU WANT TO CONTONUE(Y/N)? :"<<endl;
    cin>>c;
} while( c=='y'||c=='Y');
    return 0;
}

