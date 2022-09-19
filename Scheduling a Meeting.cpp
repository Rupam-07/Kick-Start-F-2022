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

struct Two_sets
{
    int n;
    multiset<int> upper, lower;
    long long upper_sum;
    Two_sets(int _n)
    {
        n = _n;
        upper_sum = 0;
    }
    void upper_to_lower()
    {
        if ((int)upper.size())
        {
            int k = *upper.begin();
            upper.erase(upper.find(k));
            lower.insert(k);
            upper_sum -= k;
        }
    }

    void lower_to_upper()
    {
        if ((int)lower.size())
        {
            int k = *lower.rbegin();
            lower.erase(lower.find(k));
            upper.insert(k);
            upper_sum += k;
        }
    }

    void insert(int k)
    {
        upper.insert(k);
        upper_sum += k;
        if ((int)upper.size() > n)
        {
            upper_to_lower();
        }
    }
    void erase(int k)
    {
        if (lower.find(k) != lower.end())
        {
            lower.erase(lower.find(k));
        }
        else
        {
            if (upper.find(k) != upper.end())
            {
                upper.erase(upper.find(k));
                upper_sum -= k;
                if ((int)upper.size() < n)
                    lower_to_upper();
            }
        }
    }
};

int solve_case()
{
    int n, k, x, d;
    cin >> n >> k >> x >> d;
    vector<vector<int>> starts(d), ends(d);
    vector<int> active(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int p, l, r;
        cin >> p >> l >> r;
        p--;
        starts[l].push_back(p);
        ends[r - 1].push_back(p);
    }
    Two_sets ts(k);
    for (int i = 0; i < n; i++)
        ts.insert(0);
    int ans = INF;
    for (int i = 0; i < d; i++)
    {
        for (int j : starts[i])
        {
            ts.erase(-active[j]);
            active[j]++;
            ts.insert(-active[j]);
        }

        if (i + 1 >= x)
        {
            ans = min(ans, -ts.upper_sum);
            for (int j : ends[i + 1 - x])
            {
                ts.erase(-active[j]);
                active[j]--;
                ts.insert(-active[j]);
            }
        }
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