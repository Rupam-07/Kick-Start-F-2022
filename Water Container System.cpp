#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p)
{
    return os << "(" << p.first << ", " << p.second << ") ";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x)
{
    os << "[ ";
    for (auto &y : x)
        os << y << ", ";
    return os << "]\n";
}

#define int long long
#define len(a) (int)a.size()
const long long INF = 1e18;
const double EPS = 1e-9;
const int di[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dj[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int solve_case()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> at_level(n);

    auto dfs = [&](int u, int par, int h, const auto &dfs) -> void
    {
        at_level[h]++;
        for (int v : g[u])
        {
            if (v != par)
                dfs(v, u, h + 1, dfs);
        }
    };
    dfs(0, -1, 0, dfs);
    int i = 0, ans = 0;
    vector<int> a = at_level;
    while (q--)
    {
        int u;
        cin >> u;
        u--;
        a[i]--;
        if (a[i] == 0)
            ans += at_level[i++];
    }
    cout << ans << '\n';
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int _ = 1; _ <= t; _++)
    {
        cout << "Case #" << _ << ": ";
        solve_case();
    }
    return 0;
}