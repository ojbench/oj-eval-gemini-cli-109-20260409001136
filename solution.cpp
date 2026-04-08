#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> T(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> E(n + 1, vector<long long>(n + 1, 0));

    for (int L = 1; L <= n; ++L) {
        for (int i = 1; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            if (L == 1) {
                T[i][i] = 1;
                E[i][i] = 0;
            } else {
                long long g = 0;
                for (int k = i; k <= j - 1; ++k) {
                    g = (g + T[i][k] * T[k + 1][j]) % MOD;
                }
                E[i][j] = (g * A[i][j]) % MOD;

                long long t = 0;
                for (int k = i + 1; k <= j; ++k) {
                    t = (t + E[i][k] * T[k][j]) % MOD;
                }
                T[i][j] = t;
            }
        }
    }

    cout << T[1][n] << "\n";

    return 0;
}
