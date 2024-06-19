// https://github.com/SPyofgame200/Editorial/blob/master/Olympic%20Sinh%20Vi%C3%AAn%202020%20-%20Chuy%C3%AAn%20tin%20-%20S%C6%A1n%20ph%E1%BA%A3n%20quang.md

#include <iostream>

using namespace std;

typedef long long ll;

ll f(ll n)
{
    ll res = 0;
    for (ll x = 2; x <= n; x *= 2)
        res += n / x;

    return res;
}

int main()
{
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1);
    return 0;
}
