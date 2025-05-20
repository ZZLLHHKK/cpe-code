#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

struct p {
    char c;
    int cnt = 0;
};

bool cmp(p a, p b) {
    if (a.cnt == b.cnt) return a.c < b.c;
    else return a.cnt > b.cnt;
}

int main() {
    int t;
    vector<p> arr(26);
    cin >> t;
    t++;
    for (int i = 0; i < 26; ++i) arr[i].c = 'A' + i;
    
    while (t--) {
        string a;
        getline(cin, a);
        for (int i = 0; i < a.length(); ++i) {
            if (isalpha(a[i])) {
                a[i] = toupper(a[i]);
                arr[a[i]-'A'].cnt++;
            }
        }   
    }
    sort(arr.begin(), arr.end(), cmp);
    
    for (int i = 0; i < 26; ++i) {
        if (arr[i].cnt == 0) break;
        else cout << arr[i].c << " " << arr[i].cnt << '\n';
    }
}
