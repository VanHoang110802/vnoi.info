// https://github.com/SPyofgame200/Editorial/blob/master/Olympic%20Sinh%20Vi%C3%AAn%202020%20-%20Chuy%C3%AAn%20tin%20-%20%C4%90%C6%B0%E1%BB%9Dng%20%C4%91i.md

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

const int mx[] = {+0, +1};
const int my[] = {+1, +0};

struct Info
{
    int x, y, d;
    Info (int x = 0, int y = 0, int d = 0)
    : x(x), y(y), d(d) {}
};

struct Pack
{
    int res;
    string way;
    Pack (int res = 0, string way = "")
    : res(res), way(way) {}
};

Pack min(const Pack &a, const Pack &b)
{
    if (a.res < b.res) return a; /// Left is smaller path
    if (a.res > b.res) return b; /// Right is smaller path
    return (a.way < b.way) ? a : b; /// Choose smaller lexicographical order
}

const int INF = 0x3f3f3f3f;
const int LIM = 1e3 + 13;

int n, m;
int a[LIM][LIM];
int f[LIM][LIM];
int n2[LIM][LIM];
int n5[LIM][LIM];

Pack solve_0()
{
    memset(f, -1, sizeof(f));
    f[n][m] = !a[n][m];
    
    deque<Info> S;
    S.push_back(Info(n, m, f[n][m]));
    while (S.size())
    {
        /// Take current path
        int x = S.front().x;
        int y = S.front().y;
        int d = S.front().d;
        S.pop_front();

        if (d < f[x][y]) continue; /// Not optimal
        for (int k = 0; k < 2; ++k)
        {
            int u = x - mx[k];
            int v = y - my[k];
            if (u < 1 || u > n) continue; /// Out of row
            if (v < 1 || v > m) continue; /// Out of col

            int g = f[x][y] || !a[u][v];
            if (f[u][v] < g) /// Take part with a[i][j] = 0
            {
                f[u][v] = g;
                S.push_back(Info(u, v, f[u][v]));
            }
        }
    }
    
    /// Trace back [1][1] -> [n][m]
    bool ok = false;
    int res = f[1][1];
    string way(n + m - 2, 'z');
    if (res == 0) return Pack(+INF, way);
    
    for (int x = 1, y = 1, p = 0; p < way.size(); ++p)
    {
        if (x == n) /// Top row
        {
            while (p < way.size()) way[p++] = 'L';
            break;
        }

        if (y == m) /// Top column
        {
            while (p < way.size()) way[p++] = 'D';
            break;
        }

        /// Priority contain a[i][j] = 0 -> Priority f[][] contain a[i][j] = 0 -> 'D'
        ok |= !a[x][y];
        if (ok || f[x + 1][y] >= f[x][y + 1])
        {
            way[p] = 'D';
            ++x;
        }
        else 
        {
            way[p] = 'L';
            ++y;
        }
    }

    return Pack(res, way);
}

Pack solve(int a[LIM][LIM])
{
    /// Init DP
    memset(f, +INF, sizeof(f));
    f[n][m] = a[n][m];

    deque<Info> S;
    S.push_back(Info(n, m, f[n][m]));
    while (S.size())
    {
        /// Take current path
        int x = S.front().x;
        int y = S.front().y;
        int d = S.front().d;
        S.pop_front();

        if (d > f[x][y]) continue; /// Not optimal
        for (int k = 0; k < 2; ++k)
        {
            int u = x - mx[k];
            int v = y - my[k];
            if (u < 1 || u > n) continue; /// Out of row
            if (v < 1 || v > m) continue; /// Out of col

            int g = f[x][y] + a[u][v];
            if (f[u][v] > g) /// Take smaller path
            {
                f[u][v] = g;
                S.push_back(Info(u, v, f[u][v]));
            }
        }
    }

    /// Trace back [1][1] -> [n][m]
    int res = f[1][1];
    string way(n + m - 2, 'z');
    for (int x = 1, y = 1, p = 0; p < way.size(); ++p)
    {
        if (x == n) /// Top row
        {
            while (p < way.size()) way[p++] = 'L';
            break;
        }

        if (y == m) /// Top column
        {
            while (p < way.size()) way[p++] = 'D';
            break;
        }
        
        /// Priority Smaller f[][] -> Priority 'D'
        if (f[x + 1][y] <= f[x][y + 1])
        {
            way[p] = 'D';
            ++x;
        }
        else 
        {
            way[p] = 'L';
            ++y;
        }
    }

    return Pack(res, way);
}

int main()
{
    /// FASTIO
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    /// Input
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    
    /// Construct n2[][], n5[][]
    memset(n2, 0, sizeof(n2));
    memset(n5, 0, sizeof(n5));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                /// We ban the way with zero
                n2[i][j] = +INF;
                n5[i][j] = +INF;
                continue;
            }

            /// Count factors
            for (int t = a[i][j]; t % 2 == 0; t /= 2) ++n2[i][j];
            for (int t = a[i][j]; t % 5 == 0; t /= 5) ++n5[i][j];
        }
    }

    Pack res;
    res = min(solve_0(), min(solve(n2), solve(n5)));

    /// Output
    cout << res.res << "\n" << res.way;
    return 0;
}
