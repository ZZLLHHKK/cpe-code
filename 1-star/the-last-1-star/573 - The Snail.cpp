#include <iostream>
using namespace std;

int main() {
    int h, u, d, f;

    while (cin >> h >> u >> d >> f && h) { //height, dist, slide dis, fatigue percentage
        int day = 0;
        double dis = u, climb = 0, decrease = u * (f / 100.0);
        while (1) {
            day++;
            climb += dis; 
            if (climb > h) {
                cout << "success on day " << day << '\n';
                break;
            }
            climb -= d;
            if (climb < 0) {
                cout << "failure on day " << day << '\n';
                break;
            }
            dis -= decrease;
            if (dis < 0) dis = 0;
        }
    }
}
