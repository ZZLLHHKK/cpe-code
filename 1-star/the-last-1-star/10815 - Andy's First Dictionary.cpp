#include <iostream>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    set<string> word;
    string n;

    while (getline(cin, n)) {
        for (int i = 0; i < n.size(); ++i) {
            if (isalpha(n[i]) && isupper(n[i])) 
                n[i] = tolower(n[i]);
        }
        string tmp;
        stringstream ss(n);
        while (ss >> tmp) {
            string res;
            for (int j = 0; j < tmp.size();) {
                if (islower(tmp[j])) {
                    int k = j;
                    while (islower(tmp[k]))
                        res.push_back(tmp[k++]);
                    word.insert(res);
                    res.clear();
                    j = k;
                }
                else 
                    j++;
            }    
        }
    }

    for (auto &str : word) {
        cout << str << '\n';
    }
}
