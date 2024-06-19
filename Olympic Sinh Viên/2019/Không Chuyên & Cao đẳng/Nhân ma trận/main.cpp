#include <bits/stdc++.h>
#define int long long

template<class A, class B>
bool maximize(A &a, const B& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class A, class B>
bool minimize(A &a, const B& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

using namespace std;

constexpr int MAX_N = 102;

vector<vector<int> > A;
int k, n, i, j;
long long S;

long long multiply(const __int128 x, const __int128 y) {
    return x * y % S;
}

long long add(const long long x, const long long y) {
    return (x + y) % S;
}

signed main() {
    vector<long long> row, values;

    #ifdef LOCAL
        freopen("input.INP", "r", stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);

    cin >> k >> n >> i >> j >> S;

    if (S == 1) {
        cout << 0 << '\n';
        return 0;
    }

    --i;
    --j;

    A.resize(n, vector<int>(n));

    values.resize(n);
    row.resize(n);
    row[i] = 1;

    /**

        i-th row of the identity matrix

    **/

    for (int x, y, t = 0; t < k; ++t) {
        for (x = 0; x < n; ++x)
            for (y = 0; y < n; ++y) {
                cin >> A[x][y];
                if (A[x][y] >= 0)
                    A[x][y] %= S;
                else
                    A[x][y] = (S - (-A[x][y]) % S) % S;
            }
        for (y = 0; y < n; ++y) {
            values[y] = 0;
            for (x = 0; x < n; ++x)
                values[y] = add(values[y], multiply(row[x], A[x][y]));
        }
        for (y = 0; y < n; ++y)
            row[y] = values[y];
    }

    cout << row[j] << '\n';

    return 0;
}
