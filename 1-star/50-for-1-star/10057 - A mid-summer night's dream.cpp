#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;

    while (cin >> t) {
        int arr[t + 1], mid = (t - 1) / 2, cnt = 0, dif = 0;
        for (int i = 0; i < t; ++i)
            cin >> arr[i];
        sort(arr, arr + t);
        for (int i = 0; i < t; ++i) {
            if (arr[i] == arr[mid] && (t % 2 == 1)) cnt++;
            if ((arr[i] == arr[mid] || arr[i] == arr[mid + 1]) && (t % 2 == 0)) cnt++;
        }
        if (t % 2 == 0)
            dif = arr[mid + 1] - arr[mid] + 1;
        else 
            dif = 1;
        cout << arr[mid] << " " << cnt << " " << dif << '\n';
    }
}
