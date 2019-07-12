#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
#define x first
#define y second
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
void fastInOut();
const int N = 1e4 + 5;

int n;
int bets[N];

int dp[2];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    while(cin >> n) {
        if(n == 0)
            break;
        for(int i=0; i<n; ++i)
            cin >> bets[i];
        // max subarray
        dp[(n-1)&1] = bets[n-1];
        int mx = dp[(n-1)&1];
        for(int i=n-2; i>=0; --i) {
            dp[i&1] = max(bets[i], dp[(i+1)&1] + bets[i]);
            mx = max(mx, dp[i&1]);
        }
        if(mx > 0)
            cout << "The maximum winning streak is "
                 << mx << ".\n";
        else
            cout << "Losing streak.\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
