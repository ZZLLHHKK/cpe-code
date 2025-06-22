#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi = acos(-1);
//1 min = 1 / 60 degree
void solve(double s, double ang) {
    double arc, ch;
    arc = sqrt((2 * s * s) - (2 * s * s * cos(ang * pi / 180)));
    ch = 2 * pi * s * (ang / 360.0);
    cout << fixed << setprecision(6) << ch << " " << fixed << setprecision(6) << arc << '\n';
}

int main() {
    int s, a;
    string cmd;
    
    while (cin >> s >> a >> cmd) {
        double arc, ch, ang;
        s += 6440;
        if (cmd == "deg") ang = (double)a;
        else ang = a / 60.0;

        if (ang == 180.0) {
            solve(s, ang);
            continue;
        }
        else if (ang == 360.0)
            s = 0, ang = 0;
            
        while (ang >= 360.0) ang -= 180.0;
        if (ang >= 180.0) ang = 360.0 - ang;
        solve(s, ang);
    }
}
