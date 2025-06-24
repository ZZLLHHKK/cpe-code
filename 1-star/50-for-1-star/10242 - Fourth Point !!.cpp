#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct p {
    double x, y;
    bool operator==(const p &other) {
        return (x == other.x) && (y == other.y);
    }
};

int main() {
    p arr[4];

    while (cin >> arr[0].x >> arr[0].y >> arr[1].x >> arr[1].y >> arr[2].x >> arr[2].y >> arr[3].x >> arr[3].y) {
        int check[2];
        double vx1 = 0, vy1 = 0, vx2 = 0, vy2 = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = i; j < 4; ++j) {
                if (arr[i] == arr[j] && i != j) {
                    check[0] = i, check[1] = j;
                    break; 
                }
            }
        }
        if (check[0] != 1) swap(arr[0], arr[1]);
        if (check[1] != 2) swap(arr[2], arr[3]);

        vx1 = arr[0].x - arr[1].x, vy1 = arr[0].y - arr[1].y;
        vx2 = arr[3].x - arr[2].x, vy2 = arr[3].y - arr[2].y;
        cout << fixed << setprecision(3) << vx1 + vx2 + arr[1].x << " " << fixed << setprecision(3) << vy1 + vy2 + arr[1].y << '\n';
    }
}
