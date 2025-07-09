#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ugly(1500);
    ugly[0] = 1;

    int p2 = 0, p3 = 0, p5 = 0;

    for (int i = 1; i < 1500; ++i) {
        int next = min({ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5});
        ugly[i] = next;

        if (next == ugly[p2] * 2) p2++;
        if (next == ugly[p3] * 3) p3++;
        if (next == ugly[p5] * 5) p5++;
    }

    cout << "The 1500'th ugly number is " << ugly[1499] << ".\n";
}
