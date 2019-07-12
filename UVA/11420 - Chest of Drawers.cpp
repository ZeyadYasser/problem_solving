#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
void fastInOut();
const double EPS = 1e-4;
const int MOD = 1e9 + 7;
const int N = 65 + 5;

int n, s;
ll dp[N][N][2]; // idx, cnt_secured, prv
// 0 not secured - 1 secured

ll solve(int i, int cnt, int prv) {
    if(i == n && cnt == s) return 1;
    if(i == n) return 0;
    ll &res = dp[i][cnt][prv];
    if(~res) return res;
    res = solve(i+1, cnt, 0);
    if(prv)
        res += solve(i+1, cnt+1, 1);
    else
        res += solve(i+1, cnt, 1);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //fastInOut();
    while(cin >> n >> s) {
        if(n < 0) break;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 1) << '\n';
    }
    return 0;
}
 
void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}