#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int LIM = 1e6 + 1;

/// SPyofgame linear sieving
vector<int> prime; /// prime list
vector<int> lpf; /// lowest prime factor
void sieve(int n = LIM)
{
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);

    lpf[1] = -2;
    for (int x = 3; x <= n; x += 2)
    {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
            lpf[prime[i] * x] = prime[i];
    }
}

int G[LIM];
int query()
{
    int n;
    cin >> n;

    bool ok = false;
    memset(G, 0, sizeof(G));
    for (int i = 1; i <= 2 * n; ++i)
    {
        int x;
        cin >> x;

        if (ok) continue;
        while (x > 1)
        {
            int p = lpf[x], f = 0;
            do x /= p, ++f;
            while (lpf[x] == p);
            
            if (p == 2 || p == 5) continue;
            if (i <= n)
                G[p] -= f;
            else 
            {
                G[p] += f;
                if (G[p] > 0) /// f[i] - d[i] > 0
                {
                    ok = true;
                    break;
                }
            }
        }
    }

    cout << (ok ? "repeating\n" : "finite\n");
    return 0;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int q;
    cin >> q;

    sieve();
    while (q-->0)
    {
        query();

    }
    
    return 0;
}
