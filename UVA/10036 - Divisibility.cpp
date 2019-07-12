#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
void fastInOut();
const double EPS = 1e-4;
const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

bool dp[2][105];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        int n, k; cin >> n >> k;
        for(int i=1; i<=n; i++) {
            int a; cin >> a;
            for(int ki=0; ki<k; ki++)
                dp[i%2][ki] = dp[(i-1)%2][((ki+a)%k + k)%k] | dp[(i-1)%2][((ki-a)%k + k)%k];
        }
        cout << ((dp[n%2][0]) ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}
 
void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}