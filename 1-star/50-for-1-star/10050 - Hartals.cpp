#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int d, p, party[10001] = {}, h = 0; //day, party, party day, answer
        cin >> d >> p;
        for (int i = 0; i < p; ++i)
            cin >> party[i];
        int sim[2][d];
        memset(sim, 0 ,sizeof(sim));
        sim[0][0] = 7;
        for (int i = 1; i < d; ++i) 
            sim[0][i] = (i % 7 == 0 ? 7 : i % 7);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < d; ++j) {
                if ((j + 1) % party[i] == 0)
                    sim[1][j] = 1;
            }
        }
        for (int k = 0; k < d; ++k)
            if (sim[1][k] == 1 && (sim[0][k] != 5 && sim[0][k] != 6)) h++;
        cout << h << '\n';
    }
}
