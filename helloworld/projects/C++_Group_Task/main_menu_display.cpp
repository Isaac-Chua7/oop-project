#include <iostream>
#include <vector>
using namespace std;

void showMenu() {
    cout << "============" << endl;
    cout << "    Name    " << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Quit" << endl;
    cout << "Choose an option: " << endl;
}

void showGrid() {
    const int ROWS = 3;
    const int COLS = 6;

    vector<vector<string>> grid(ROWS, vector<string>(COLS, "   "));

    // defenders
    grid[0][0] = "♢5";
    grid[1][0] = "⚀3";
    grid[2][0] = "⚁4";

    // attackers
    grid[0][5] = "♖5";
    grid[1][5] = "♖6";
    grid[2][5] = "♖7";

    cout << endl << "------Cash $100------" << endl;
    cout << "------Shop------" << endl;

    for (int rowOfGrid = 0; rowOfGrid < ROWS; rowOfGrid++) {
        for (int colOfGrid = 0; colOfGrid < COLS; colOfGrid++) {
            cout << "[ " << grid[rowOfGrid][colOfGrid] << " ]";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                int inGameChoice;
                do {
                    cout << "Starting game..." << endl;
                    showGrid();
                    cout << "1. Continue" << endl << "2. Return To Menu" << endl;
                    cin >> inGameChoice;

                    if (inGameChoice == 1) {
                        cout << "Game continues ... (later: moves, actions, etc.)" << endl;
                    }
                } while (inGameChoice != 2);
                break;
            case 2: 
                cout << "Settings (diff, sound vol)..." << endl;
                break;
            case 3:
                cout << "Quitting game" << endl;
                break;
            default:
                cout << "Invalid choice. Try again" << endl;

        }
    } while (choice != 3);
    

    return 0;
}
