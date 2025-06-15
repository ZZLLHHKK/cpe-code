#include <iostream>
#include <vector>
using namespace std;

vector<int> decToBi(int i) {
    vector<int> bi;
    while (i > 0) {
        bi.push_back(i % 2);
        i /= 2;
    }
    return bi;
}

vector<int> hexTobi(int i) {
    int b = 1, ans = 0;
    while (i > 0) {
        ans += (i % 10) * b;
        i /= 10;
        b *= 16;
    }
    return decToBi(ans);
}

int count(vector<int> bi) {
    int cnt = 0;
    for (int i = 0; i < bi.size(); ++i) 
        if (bi[i] == 1) cnt++;
    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        vector<int> b1, b2;
        cin >> n;
        b1 = decToBi(n);
        b2 = hexTobi(n);
        cout << count(b1) << " " << count(b2) << '\n';
    }
}
