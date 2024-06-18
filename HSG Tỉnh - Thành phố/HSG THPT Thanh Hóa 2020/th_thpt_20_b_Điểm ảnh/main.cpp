#include <iostream>
#include <iomanip>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN];
int n, MAX = 0;

void XuLy()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        a[x]++;
        MAX = max(MAX, a[x]);
    }
    cout << MAX;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    XuLy();
    cout << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}
