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
    int d, n, x;
    cin >> d >> n >> x;
    vector<int> q(n), l(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i] >> l[i] >> v[i];
    }
    map<int, vector<int>> available_at;
    available_at[0] = vector<int>();
    for (int i = 0; i < n; i++)
    {
        if (d - l[i] >= 1)
            available_at[d - l[i]].push_back(i);
    }
    int last = d + 1, ans = 0;
    set<pair<int, int>> have;
    for (auto it = available_at.rbegin(); it != available_at.rend(); it++)
    {
        int seeds = (last - it->first) * x;
        while (len(have) && seeds)
        {
            int i = have.begin()->second;
            have.erase(have.begin());
            int use = min(q[i], seeds);
            q[i] -= use;
            seeds -= use;
            ans += use * v[i];
            if (q[i])
                have.insert({-v[i], i});
        }
        for (int i : it->second)
            have.insert({-v[i], i});
        last = it->first;
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