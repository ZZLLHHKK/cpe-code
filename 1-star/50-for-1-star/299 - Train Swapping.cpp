#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, cnt = 0;
        cin >> n;
        vector<int> arr(n+1);
        for (int i = 0; i < n; ++i) 
            cin >> arr[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
}
