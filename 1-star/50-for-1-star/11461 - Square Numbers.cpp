#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    
    while (cin >> a >> b && a && b) 
        cout << floor(sqrt(b)) - ceil(sqrt(a)) + 1 << '\n';
}
