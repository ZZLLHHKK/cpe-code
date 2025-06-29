#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n;

    while (cin >> n && n) {
        bitset<32> bits(n);
        string s = bits.to_string();
        s = s.substr(s.find('1'));
        cout << "The parity of " << s << " is " << bits.count() << " (mod 2).\n";
    }
}
