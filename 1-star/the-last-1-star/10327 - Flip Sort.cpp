#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;

    while (cin >> n) { //insertion sort
        int cnt = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) 
            cin >> arr[i];
        for (int i = 1; i < n; ++i) {
            int j = i - 1;
            while (arr[j + 1] < arr[j] && j >= 0) {
                swap(arr[j + 1], arr[j]);
                cnt++, j--;
            }
        }
        cout << "Minimum exchange operations : " << cnt << '\n';
    }
}
