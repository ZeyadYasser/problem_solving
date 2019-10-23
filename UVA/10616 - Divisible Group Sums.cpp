#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void fastInOut();
const int N = 2e2 + 5;

ll n, q, d, m;
ll num[N];

ll dp[N][22][12]; // dp[N][D][M]
ll solve(ll i, ll _d, ll _m)
{
    if(_m == m)
        return (ll)(_d == 0);
    if(i == n)
        return 0;
    ll &res = dp[i][_d][_m];
    if(~res)
        return res;
    res = solve(i+1, _d, _m); // don't take i
    ll _n = num[i];
    if(_n < 0)
        _n += d*4e9;
    res += solve(i+1, (_d+_n)%d, _m+1); // take i

    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int setid = 1;
    while(cin >> n >> q) {
        if(n == 0 && q == 0)
            break;
        for(int i=0; i<n; ++i)
            cin >> num[i];
        cout << "SET " << setid << ":\n";
        for(int i=1; i<=q; ++i) {
            memset(dp, -1, sizeof(dp));
            cin >> d >> m;
            cout << "QUERY " << i << ": "
                 << solve(0, 0, 0) << '\n';
        }
        setid++;
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
