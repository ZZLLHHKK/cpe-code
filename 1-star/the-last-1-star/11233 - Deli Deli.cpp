#include <iostream>
#include <map>
using namespace std;

int main() {
    int l, r;
    
    while (cin >> l >> r) {
        map<string, string> mp;
        string a, b, str;
        for (int i = 0; i < l; ++i) {
            cin >> a >> b;
            mp[a] = b;
        }
        for (int j = 0; j < r; ++j) {
            cin >> str;
            int s = str.size();
            if (mp.find(str) != mp.end())
                cout << mp[str] << '\n';
            else if (str[s - 1] == 'y' && (str[s - 2] != 'a' && str[s - 2] != 'e' && str[s - 2] != 'i' && str[s - 2] != 'o' && str[s - 2] != 'u')) {
                str.pop_back();
                cout << str << "ies\n";
            }
            else if (str[s - 1] == 'o' || str[s - 1] == 's' || str[s - 1] == 'x' || (str[s - 1] == 'h' && str[s - 2] == 'c') || (str[s - 1] == 'h' && str[s - 2] == 's')) 
                cout << str << "es\n";
            else 
                cout << str << "s\n";
        }
    }
}
