#include <iostream>
#include <vector>
using namespace std;

int main() {

    // define its rows and cols
    const int rows = 3;
    const int cols = 6;

    // showing a 2D grid
    vector<vector<string>> grid(rows, vector<string>(cols, "   "));

    // place defenders with health
    grid[0][0] = "♞5";
    grid[1][0] = "♧3";
    grid[2][0] = "♞1";

    // place attackers
    grid[0][5] = "⚀5";
    grid[1][5]= "⚀5";
    grid[2][5] = "⚀5";

    // display the interactions
    cout << "---$100---" << endl;
    cout << "---Shop---" << endl;

    // print the grid
    for (int rowgrid = 0; rowgrid < rows; rowgrid++) {
        for (int colgrid = 0; colgrid < cols; colgrid++)  {
            cout << "[ " << grid[rowgrid][colgrid] << " ]";
        }
        cout << endl;
    }
    
    // cout <<
    // "------$0------                        " << endl <<
    // "-----Shop-----                        " << endl <<
    // "[ P1(5/5)] [   ] [   ] [   ] [   ] [ Z1(5/5)] " << endl;

    return 0;

}