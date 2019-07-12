#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void fastInOut();
const int N = 1e2 + 2;

int n, m;
struct dress
{
    int p, f;
    bool operator<(const dress &d)
    {
        if(p == d.p)
            return f > d.f;
        return p < d.p;
    }
} d[N];

int dp[N][11002]; // dp[N][M]
int solve(int i, int money)
{
    if(i == n)
        return 0;
    int &res = dp[i][money];
    if(~res)
        return res;
    res = solve(i+1, money);
    if(money+d[i].p <= m || (money+d[i].p > 2000 && money+d[i].p<=m+200))
        res = max(res, solve(i+1, money+d[i].p)+d[i].f);
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    while(cin >> m >> n) {
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++)
            cin >> d[i].p >> d[i].f;
        sort(d, d+n);
        cout << solve(0, 0) << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
