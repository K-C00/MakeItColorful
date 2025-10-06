#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;


int main() {
    unsigned seed = time(0);
    srand(seed);
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    
    string player1, player2;

    char round;

    do {
        int p1dice = rand() % 20 + 1;
        int p2dice = rand() % 20 + 1;
        string p1status, p2status;

        SetConsoleTextAttribute(screen, 7);
        cout << "=========Dice Roller=========" << endl;
        cout << "Enter name for player 1: ";
        cin >> player1;
        cout << "Enter name for player 2: ";
        cin >> player2;
        cout << "-----------------------------" << endl;

        cout << player1 << " rolls a " << p1dice;
        if (p1dice == 1) {
            SetConsoleTextAttribute(screen, 4);
            p1status = "Critical Fail";
            SetConsoleTextAttribute(screen, 7);
        } else if (p1dice == 20){
            SetConsoleTextAttribute(screen, 2);
            p1status = "Critical Success";
            SetConsoleTextAttribute(screen, 7);   
        }
        if (!p1status.empty()) {
            cout << "\n" << player1 << " rolled " << p1status << endl;
        } else {
            SetConsoleTextAttribute(screen, 3);
            cout << "\n * Normal roll for " << player1;
            SetConsoleTextAttribute(screen, 7);
        }
        cout << endl;

        cout << player2 << " rolls a " << p2dice;
        if (p2dice == 1) {
            SetConsoleTextAttribute(screen, 4);
            p2status = "Critical Fail";
            SetConsoleTextAttribute(screen, 7);
        } else if (p2dice == 20) {
            SetConsoleTextAttribute(screen, 2);
            p2status = "Critical Success";
            SetConsoleTextAttribute(screen, 7);
        }
        if (!p2status.empty()) {
            cout << "\n" << player2 << " rolled " << p2status << endl;
        } else {
            SetConsoleTextAttribute(screen, 3);
            cout << "\n  * Normal roll for " << player2;
            SetConsoleTextAttribute(screen, 7);
        }
        cout << endl;

        cout << "-----------------------------" << endl;
        if (p1dice > p2dice) {
            cout << player1 << " wins this round\n" << endl;
        } else if (p1dice < p2dice) {
            cout << player2 << " wins this round\n" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
        SetConsoleTextAttribute(screen, 6);
        cout << "Play Again? (Y/N)";
        cin >> round;
        round = toupper(round);
        SetConsoleTextAttribute(screen, 7);

        while (round != 'Y' && round != 'N') {
            SetConsoleTextAttribute(screen, 4);
            cout << "\nERROR: Please enter Y or N." << endl;
            SetConsoleTextAttribute(screen, 7);
            cin >> round;
            round = toupper(round);
        } 
        
        if (round == 'N') {
            cout << "\nGAME OVER" << endl;
            break;
        }
    } while (round == 'Y');
    return 0;
}