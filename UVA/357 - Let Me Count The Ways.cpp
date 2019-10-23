#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void fastInOut();
const int N = 3e4 + 3;

const int coins[5] = {1, 5, 10, 25, 50};

ll dp[6][N];

ll solve(int i, int rem)
{
    if(rem < 0) return 0;
    if(rem == 0) return 1;
    if(i == 5) return 0;
    ll &res = dp[i][rem];
    if(~res) return res;
    res = solve(i+1, rem) + solve(i, rem - coins[i]);
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    memset(dp, -1, sizeof(dp));
    ll res = solve(0, 30000);
    int k;
    while(cin >> k) {
        if(solve(0, k) == 1)
            cout << "There is only 1 way to produce "
                 << k << " cents change.\n";
        else
            cout << "There are " << solve(0, k) << " ways to produce "
                 << k << " cents change.\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
