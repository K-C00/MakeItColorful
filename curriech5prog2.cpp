#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;


int main() {
    double speed, distance, time;
    int totalHours = 0;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "==============Trip Calculator==============" << endl;
    cout << "Enter speed: ";
    cin >> speed;
    cout << "Enter distance of travel: ";
    cin >> distance;
    time = distance / speed;
    cout << "You will reach your destination in " << ceil(time) << " hours." << endl; 
    
    cout << "-------------------------------------------" << endl;
    double totalDistance = 0.0;
    while (totalDistance < distance) {
        totalHours++;
        totalDistance += speed;

        if (totalDistance > distance) {
            totalDistance = distance;
        }
        cout << "After " << totalHours << " hours, you have traveled " << totalDistance << " miles." << endl;
    }
    cout << "===========================================" << endl;
    return 0;
}