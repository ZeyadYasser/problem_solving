#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
void fastInOut();
const double EPS = 1e-4;
const int MOD = 1e9 + 7;
const int N = 10 + 5;

int n;
int row[N], col[N];

int dp[N][N];

int solve(int i, int j) {
    if(i == j) return 0;
    int &res = dp[i][j];
    if(~res) return res;
    res = 1e9;
    for(int k=i; k<j; ++k)
        res = min(res, solve(i, k) + solve(k+1, j) + row[i]*col[k]*col[j]);
    return res;
}

void build(int i, int j) {
    if(i==j) {
        cout << "A" << i+1;
        return;
    }
    const int &res = dp[i][j];
    for(int k=i; k<j; ++k) {
        if(res == solve(i, k) + solve(k+1, j) + row[i]*col[k]*col[j]) {
            if(i != k) cout << '(';
            build(i, k);
            if(i != k) cout << ')';
            cout << " x ";
            if(j != k+1) cout << '(';
            build(k+1, j);
            if(j != k+1) cout << ')';
            return;
        }
    }
    return;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int C = 0;
    while(cin >> n) {
        C++;
        if(n == 0) break;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; ++i)
            cin >> row[i] >> col[i];
        solve(0, n-1);
        cout << "Case " << C << ": ";
        cout << '('; build(0, n-1); cout << ')';
        cout << '\n';
    }
    return 0;
}
 
void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}