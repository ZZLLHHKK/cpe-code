#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

#define ll long long
string bang[5] = {"kuti", "lakh", "hajar", "shata", ""};

void divide(vector<vector<ll>> &arr, vector<ll> &two) {
    for (int i = 0; i < 2; ++i) {
        int b = 100;
        for (int j = 4; j >= 0; --j) {
            if (j == 3 || j == 0) b = 10;
            else b = 100;
            arr[i][j] = two[i] % b;
            two[i] /= b;
        }
    }
}

int main() {
    int t = 1;
    ll n;

    while (cin >> n) {
        if (n == 0) {
            cout << setw(4) << t++ << ". 0\n";
            continue;
        }
        string ans;
        vector<ll> two = {0, 0};
        vector<vector<ll>> arr(2, vector<ll>(5));
        two[1] = n % 10000000;
        n /= 10000000;
        two[0] = n % 100000000;
        divide(arr, two);
        cout << setw(4) << t++ << ". ";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (arr[i][j] != 0) {
                    ans += to_string(arr[i][j]) + " " + bang[j];
                    if (j != 4)
                        ans += " ";
                }
                else 
                    continue;
            }
            if (n != 0 && i == 0)
                ans += "kuti ";
        }
        ans.pop_back();
        cout << ans << "\n";
    }
}

/**
Note: be sure your output form can not be print out unnecessary space, or else it will PE
**/
