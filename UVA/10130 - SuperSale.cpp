#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void fastInOut();
const int N = 1000 + 2;

int n, g, p[N], w[N];

int dp[N][32];
int solve(int i, int _w) {
    if(i == n) return 0;
    int &res = dp[i][_w];
    if(~res) return res;
    res = solve(i+1, _w);
    if(_w - w[i] >= 0)
        res = max(res, solve(i+1, _w - w[i]) + p[i]);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> p[i] >> w[i];
        cin >> g;
        int res = 0;
        for(int i=0; i<g; ++i) {
            memset(dp, -1, sizeof(dp));
            int wp; cin >> wp;
            res += solve(0, wp);
        }
        cout << res << '\n';
    }
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
