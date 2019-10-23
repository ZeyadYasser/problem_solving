#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
void fastInOut();
const double EPS = 1e-4;
const int MOD = 1e9 + 7;
const int N = 17;

int n;

int x[N], y[N];
double dist[N][N];

double dp[1<<N];
double solve(int mask) {
    if(__builtin_popcount(mask) == n) return 0;
    double &res = dp[mask];
    if(res > 0) return res;
    res = 1e9;
    for(int i=0; i<n; ++i) {
        if(mask & (1<<i)) continue;
        for(int j=0; j<n; ++j) {
            if(mask & (1<<j) || i == j) continue;
            res = min(res, solve(mask | (1<<i) | (1<<j)) + dist[i][j]);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int C = 0;
    while(cin >> n) {
        C++;
        if(n == 0) break;
        n<<=1;
        fill(dp, dp + (1<<n) + 1, -1);
        string dumdum;
        for(int i=0; i<n; ++i)
            cin >> dumdum >> x[i] >> y[i];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(i != j)
                    dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        cout << fixed << setprecision(2)
             << "Case " << C << ": "
             << solve(0) << '\n';
    }
    return 0;
}
 
void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}