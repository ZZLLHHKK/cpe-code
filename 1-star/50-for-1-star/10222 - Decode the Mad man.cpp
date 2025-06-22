#include <iostream>
#include <cctype>
using namespace std;
string str = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main() {
    string s;
    
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) && isupper(s[i])) s[i] = tolower(s[i]);
            int key = str.find(s[i]) - 2;
            if (s[i] != ' ') 
                cout << str[key];
            else 
                cout << " ";
        }
        cout << '\n';
    }
}
