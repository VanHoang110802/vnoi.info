#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void XuLy()
{
    string a,b;
    cin >> a >> b;
    int x, y;
    int m, n;
    n = a.size();
    m = b.size();
    x = a[n - 1] - '0';
    y = b[m - 1] - '0';
    if(m == 1 && y == 0)
    {
        cout << 1;
        return;
    }
    if(m >= 2)
    {
        y = (b[m - 2] - '0') * 10 + y;
    }
    if(x == 1)
    {
        cout << 1;
        return;
    }
    if(x == 0)
    {
        cout << 0;
        return;
    }
    if(x == 5)
    {
        cout << 5;
        return;
    }
    if(x == 6)
    {
        cout << 6;
        return;
    }
    if(x == 9)
    {
        if(y % 2) cout << 9;
        else cout << 1;
        return;
    }
    if(x == 4)
    {
        if(y % 2) cout << 4;
        else cout << 6;
        return;
    }
    if(x == 2)
    {
        if(y % 4 == 1) cout << 2;
        if(y % 4 == 2) cout << 4;
        if(y % 4 == 3) cout << 8;
        if(y % 4 == 0) cout << 6;
        return;
    }
    if(x == 3)
    {
        if(y % 4 == 1) cout << 3;
        if(y % 4 == 2) cout << 9;
        if(y % 4 == 3) cout << 7;
        if(y % 4 == 0) cout << 1;
        return;
    }
    if(x == 7)
    {
        if(y % 4 == 1) cout << 7;
        if(y % 4 == 2) cout << 9;
        if(y % 4 == 3) cout << 3;
        if(y % 4 == 0) cout << 1;
        return;
    }
    if(x == 8)
    {
        if(y % 4 == 1) cout << 8;
        if(y % 4 == 2) cout << 4;
        if(y % 4 == 3) cout << 2;
        if(y % 4 == 0) cout << 6;
        return;
    }
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
