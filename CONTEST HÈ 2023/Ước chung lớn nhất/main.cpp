#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define int long long
int N, X, ans = 1;

void XuLy()
{
    cin >> N >> X;
    if(N == 1)
    {
        cout << X;
        return;
    }
    for(int i = 1; pow(i, N) <= X; i++)
    {
        if(X % (int)pow(i, N) == 0)
        {
            ans = i;
        }
    }
    cout << ans;
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
