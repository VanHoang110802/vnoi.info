#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long

void XuLy()
{
    double n, a, b, x, y, z;
    cin >> n >> a >> b;
    double Min = 1000000000000000.0;
    for(int i = n - 1; i >= 0; --i)
    {
        cin >> x >> y >> z;
        Min = min(Min, sqrt((x - a) * (x - a) + (y - b) * (y - b)) - z);
    }
    int ans = Min;
    if(Min == ans) cout << ans-1;
    else cout << ans;
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
