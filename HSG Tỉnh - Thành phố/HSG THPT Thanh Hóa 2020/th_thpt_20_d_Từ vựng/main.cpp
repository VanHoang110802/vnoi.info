#include <iostream>
#include <iomanip>
using namespace std;

#define int long long

void XuLy()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int d = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            d++;
        }
    }
    cout << d * (n - d) << '\n';
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
