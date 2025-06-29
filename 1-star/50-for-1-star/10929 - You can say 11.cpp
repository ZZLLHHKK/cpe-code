#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string n;

    while (getline(cin, n) && !(n[0] == '0' && n.size() == 1)) {
        int sum = 0;
        string num;
        for (int i = 0; i < n.size(); ++i) {
            if (i % 2 && isdigit(n[i])) sum += (n[i] - '0'), num.push_back(n[i]);
            if (!(i % 2) && isdigit(n[i])) sum -= (n[i] - '0'), num.push_back(n[i]);
        }
        if (sum % 11 == 0) 
            cout << num << " is a multiple of 11.\n";
        else 
            cout << num << " is not a multiple of 11.\n";
    }
}
