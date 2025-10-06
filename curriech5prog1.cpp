#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char choice;
    do {

        for (int i = 32; i <=128; i++) {
            cout << (char)i << " ";

            if (i % 16 == 15) {
                cout << endl;
            }
        } cout << endl;

        cout << "Would you like to play again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

        while (choice != 'Y' && choice != 'N') {
            cout << "Invalid input. Please enter Y or N." << endl;
            cin >> choice;
            choice = toupper(choice);
        } 
        
        if (choice == 'N') {
            cout << "Goodbye!" << endl;
            break;
        }
    } while (choice == 'Y'); 
    return 0;
}