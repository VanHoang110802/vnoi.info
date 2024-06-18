#include <iostream>
#include <iomanip>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN], t[MAXN], d[3];

void XuLy()
{
    string s;
    cin >> s;
    int n = s.size();
    s = '0' + s;
    for(int i = 1; i <= n; i++)
    {
        a[i] = s[i] - 48;
        t[i] = t[i - 1] + a[i];
    }
    int k = t[n] % 3;
    int kq = 0;
    for(int i = 0; i <= n; i++)
    {
        int j = t[i] % 3 - k;
        if(j < 0) j = j + 3;

        kq = kq + d[j];
        d[t[i] % 3]++;
    }
    if(k > 0) kq--;
    cout << kq;
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
