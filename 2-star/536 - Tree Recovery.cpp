#include <iostream>
#include <string>
using namespace std;
string preord, inord, postord;

void build(string &res, int preL, int preR, int inL, int inR) {
    if (preL > preR || inL > inR) return;
    char root = preord[preL];
    int inMid = inord.find(root);
    int leftSize = inMid - inL;
    build(res, preL + 1, preL + leftSize, inL, inMid - 1); //left
    build(res, preL + leftSize + 1, preR, inMid + 1, inR); //right
    res.push_back(root); //middle
}

int main() {
    
    while (cin >> preord >> inord) {
        string res;
        build(res, 0, preord.size() - 1, 0, inord.size() - 1);
        cout << res << '\n'; 
    }
}
