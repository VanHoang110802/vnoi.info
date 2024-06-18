#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return (a > b);
}

void XuLy()
{
    int n;
    cin >> n;
    vector<string> arr;
    for(int i=1; i<=n; ++i)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(),cmp);
    for(auto x:arr) cout << x;
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
