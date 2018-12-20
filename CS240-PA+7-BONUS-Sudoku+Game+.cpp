// CS240-PA+7-BONUS-Sudoku+Game+.cpp
// Author:  Wei Lin
// Date:    12/2/2018
// Purpose: To check a Sudoku game and show its result in detail.
#include <iostream>
#include <set>
using namespace std;

void checkSudoku(int S[]);
void print(int S[]);
bool hasProblemRow(int S[], int row);
bool hasProblemCol(int S[], int col);
bool hasProblemSqu(int S[], int Squ);

int main() {
    int S1[] = {1,2,3,4,5,6,7,8,9,
                2,3,4,5,6,7,8,9,1,
                3,4,5,6,7,8,9,1,2,
                4,5,6,7,8,9,1,2,3,
                5,6,7,8,9,1,2,3,4,
                6,7,8,9,1,2,3,4,5,
                7,8,9,1,2,3,4,5,6,
                8,9,1,2,3,4,5,6,7,
                9,1,2,3,4,5,6,7,8};

    int S2[] = {1,2,3,4,5,6,7,8,9,
                4,5,6,7,8,9,1,2,3,
                7,8,9,1,2,3,4,5,6,
                2,3,4,5,6,7,8,9,1,
                5,6,7,8,9,1,2,3,4,
                8,9,1,2,3,4,5,6,7,
                3,4,5,6,7,8,9,1,2,
                6,7,8,9,1,2,3,4,5,
                9,1,2,3,4,5,6,7,8};

    int S3[] = {1,2,3,4,5,6,7,8,2,
                4,5,6,7,8,9,1,2,3,
                7,8,9,1,2,3,4,5,6,
                2,3,4,5,6,7,8,9,1,
                5,6,7,8,9,1,2,3,4,
                8,9,1,2,3,4,5,6,7,
                3,4,5,6,7,8,9,1,2,
                6,7,8,9,1,2,3,4,5,
                9,1,2,3,4,5,6,7,8};

    int S4[] = {1,2,3,4,5,6,7,8,9,
                4,5,6,7,8,9,1,2,3,
                7,8,9,1,2,3,4,5,6,
                2,3,4,5,6,7,8,9,1,
                5,6,7,8,9,1,2,3,4,
                8,9,1,2,3,4,5,6,7,
                3,4,5,6,7,8,9,1,2,
                6,7,8,9,1,8,3,4,5,
                9,1,2,3,4,5,6,7,8};

    int* Ss[] = {S1, S2, S3, S4};

    cout << "Welcome to play the game of Sudoku!\n";

    for (int i = 0; i < 4; i++) {
        cout << "Your game " << i+1 << " is as follows:\n";
        print(Ss[i]);
        cout << "Your game " << i+1 << ": ";
        checkSudoku(Ss[i]);
        cout << "\n\n";
    }
}

void print(int S[]) {
    for (int i = 0; i < 81; i++) {
        cout << S[i];
        if ((i+1) % 9 == 0) cout << "\n";
    }
}

void checkSudoku(int S[]) {
    bool hasProblem = false;
    for (int i = 0; i < 9; i++) {
        if (hasProblemRow(S, i)) {
            cout << "Row " << i+1 << " has a problem. ";
            hasProblem = true;
        }
        if (hasProblemCol(S, i)) {
            cout << "Column " << i+1 << " has a problem. ";
            hasProblem = true;
        }
        if (hasProblemSqu(S, i)) {
            cout << "Square " << i+1 << " has a problem. ";
            hasProblem = true;
        }
    }
    if (!hasProblem) {
        cout << "Congratulations! You won the game.\n";
    }
}

bool hasProblemRow(int S[], int row) {
    set<int> intSet;
    for (int i = row*9; i < (row+1)*9; i++) {
        if (intSet.find(S[i]) != intSet.end()) return true;
        intSet.insert(S[i]);
    }
    return false;
}

bool hasProblemCol(int S[], int col) {
    set<int> intSet;
    for (int i = col; i < 81; i += 9) {
        if (intSet.find(S[i]) != intSet.end()) return true;
        intSet.insert(S[i]);
    }
    return false;
}

bool hasProblemSqu(int S[], int Squ) {
    set<int> intSet;
    for (int row = (Squ/3)*3; row < (Squ/3 + 1)*3; row++) {
        for (int i = (Squ%3)*3; i < (Squ%3+1)*3; i++) {
            if (intSet.find(S[row*9+i]) != intSet.end()) return true;
            intSet.insert(S[row*9+i]);
        }
    }
    return false;
}
