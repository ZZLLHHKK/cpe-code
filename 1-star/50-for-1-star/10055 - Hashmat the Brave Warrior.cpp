#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, b;

    while (cin >> a >> b) 
        cout << labs(a - b) << '\n';
}
