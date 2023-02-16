//
//  hw1_sparseMatrix.cpp
//  Assignment 1
//  Created by Jared Rubio on 9/11/22.
//

#include <iostream>
using namespace std;
class matrix {
public:
    void SetEntry(int i, int j, int v);
    int GetEntry(int i, int j);
    int CountNonZero();
    void GetSparseRep();
    int* SparseRow, * SparseCol, * SparseVal;
private:
    int m[3][5];
};
void matrix::SetEntry(int i, int j, int v) {
    
    m[i][j] = v;
}
int matrix::GetEntry(int i, int j) {
    
    return m[i][j];
}
int matrix::CountNonZero() {
  
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                ++counter;
            }
        }
    }
    return counter;
}
void matrix::GetSparseRep() {
    
    SparseRow = new int[3];
    SparseCol = new int[5];
    SparseVal = new int[15];
    
    int holder = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                SparseRow[holder] = i;
                SparseCol[holder] = j;
                SparseVal[holder] = m[i][j];
                holder++;
            }
        }
    
    }
}
int main()
{
    matrix x;
    
    int temp, mode;
    cin >> mode;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp;
            x.SetEntry(i, j, temp);
        }
    }
    switch (mode) {
    
    case 1:
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                cout << x.GetEntry(i, j) << endl;
            }
        }
        break;
    
    case 2:
        cout << x.CountNonZero() << endl;
        break;
    case 3:
        x.GetSparseRep();
        for (int i = 0; i < x.CountNonZero(); i++) {
            cout << x.SparseRow[i] << ' ' << x.SparseCol[i] << ' ' <<
x.SparseVal[i] << endl;
        }
        break;
    }
    return 0;
}
