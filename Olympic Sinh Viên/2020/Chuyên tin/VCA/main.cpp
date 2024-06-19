// https://github.com/SPyofgame200/Editorial/blob/master/Olympic%20Sinh%20Vi%C3%AAn%202020%20-%20Chuy%C3%AAn%20tin%20-%20VCA.md

#inlude <iostream>

using namespace std;

int cnt[256];
int main()
{
    /// Input
    int k;
    string s;
    cin >> k >> s;
    
    /// Calculate
    int res = +INF;
    cnt['A'] = cnt['V'] = cnt['C'] = 0;
    for (int l = 0, r = -1; l < s.size(); --cnt[s[l++]])
    {
        while (r + 1 < s.size() && (cnt['A'] < k || cnt['V'] < k || cnt['C'] < k)) ++cnt[s[++r]];
        if (cnt['A'] < k || cnt['V'] < k || cnt['C'] < k) break;

        int t = 0;
        t += cnt['A'] - k;
        t += cnt['V'] - k;
        t += cnt['C'] - k;
        minimize(res, t);
    }
    
    /// Output
    cout << res;
    return 0;
}
