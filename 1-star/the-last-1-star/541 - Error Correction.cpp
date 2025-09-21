#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int m[n][n], row[n] = {}, col[n] = {}, checkRow, checkCol, cntR = 0, cntC = 0;
        bool rowEven = true, colEven = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
                row[i] += m[i][j];
                col[j] += m[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (row[i] % 2) rowEven = false, checkRow = i + 1, cntR++;
            if (col[i] % 2) colEven = false, checkCol = i + 1, cntC++;
        }
        if (rowEven && colEven) 
            cout << "OK\n";
        else if ((rowEven == true && colEven == false) || (rowEven == false && colEven == true) || cntR > 1 || cntC > 1)
            cout << "Corrupt\n";
        else 
            cout << "Change bit (" << checkRow << "," << checkCol << ")\n";
    }
}
