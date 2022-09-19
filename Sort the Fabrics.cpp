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
    int n;
    cin >> n;
    vector<pair<string, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    vector<pair<string, pair<int, int>>> b = a, c = a;
    sort(b.begin(), b.end(), [&](pair<string, pair<int, int>> i, pair<string, pair<int, int>> j) -> bool
         { return make_pair(i.first, i.second.second) < make_pair(j.first, j.second.second); });

    sort(c.begin(), c.end(), [&](pair<string, pair<int, int>> i, pair<string, pair<int, int>> j) -> bool
         { return make_pair(i.second.first, i.second.second) < make_pair(j.second.first, j.second.second); });
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += b[i].second.second == c[i].second.second;
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