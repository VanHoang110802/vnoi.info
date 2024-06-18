#include <iostream>
#include <iomanip>
#include <algorithm>
//#include <vector>
#include <unordered_map>
using namespace std;

#define int long long
const int MAXN = 1e5 + 7;
//int cnt[MAXN];
unordered_map<int, int> cnt;
int demtg = 0;
int a[MAXN];

bool OK(int a, int b, int c)
{
    return (a + b > c);
}

bool tgnhon(int a, int b, int c)
{
    return (a * a + b * b > c * c);
}

int demvuong(int n)
{
    int kq = 0;
    for(int i = 1; i <= n - 1; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            cnt[a[i] * a[i] + a[j] * a[j]]++;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        kq = kq + cnt[a[i] * a[i]];
    }
    return kq;
}

int demnhon(int n)
{
    int kq = 0;
    int d, c;
    for(int i = 1; i <= n - 2; ++i)
    {
        d = i + 2;
        c = i + 2;
        for(int j = i + 1; j <= n - 1; ++j)
        {
            while(c <= n && OK(a[i], a[j], a[c]))
            {
                c++;
            }
            demtg = demtg + c - j - 1;
            while(d <= n && tgnhon(a[i], a[j], a[d]))
            {
                d++;
            }
            if(d - 1 <= c)
            {
                kq = kq + d - j - 1;
            }
        }
    }
    return kq;
}

void XuLy()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    int vuong = demvuong(n);
    int nhon = demnhon(n);
    int tu = demtg - vuong - nhon;
    cout << nhon << ' ' << vuong  << ' ' << tu << '\n';
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
