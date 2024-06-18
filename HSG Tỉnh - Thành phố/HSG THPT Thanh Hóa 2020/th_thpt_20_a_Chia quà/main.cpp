#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
using namespace std;

#define fi first
#define se second
#define int long long
int test;

void CinTest(int vanhoang)
{
    if(vanhoang > 0) cin >> test;
    else test = 1;
}

int DemUoc(int n)
{
    int cnt = 0;
    for(int i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(i * i == n) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}

signed main()
{
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); CinTest(1 - 1);
    while(test--)
    {
        int n, m; cin >> n >> m;
        cout << DemUoc(__gcd(n, m)) << '\n';
    }
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}
