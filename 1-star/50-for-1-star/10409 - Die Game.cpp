#include <iostream>
using namespace std;

int main() {
    int t;

    while (cin >> t && t != 0) {
        int top = 1, n = 2, w = 3, s = 5, e = 4; //senw
        string cmd;
        for (int i = 0; i < t; ++i) {
            cin >> cmd;
            if (cmd == "north") 
                n = top, top = s, s = 7 - n;
            else if (cmd == "south") {
                int tmp = n;
                n = 7 - top, top = tmp, s = 7 - n;
            }
            else if (cmd == "east") {
                int tmp = top;
                top = w, w = 7 - tmp, e = 7 - w;
            }
            else if (cmd == "west") {
                int tmp = top;
                w = tmp, top = e, e = 7 - w;
            }
        }
        cout << top << '\n';
    }
}
