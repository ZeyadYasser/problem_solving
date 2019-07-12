#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void fastInOut();
const int N = 30 + 2;

int t, w, n;

struct treasure
{
    int d, v;
};
treasure ts[N];

int dp[N][1002];
int solve(int i, int _t)
{
    if(i == n)
        return 0;
    int &res = dp[i][_t];
    if(~res)
        return res;
    res = solve(i+1, _t);
    if(_t+3*w*ts[i].d <= t)
        res = max(res, solve(i+1, _t+3*w*ts[i].d) + ts[i].v);
    return res;
}

vector<int> ans;
void build(int i, int _t)
{
    if(i == n)
        return;
    const int &res = dp[i][_t];
    if(res == solve(i+1, _t)) {
        build(i+1, _t);
        return;
    }
    if(_t+3*w*ts[i].d <= t) {
        if(res == solve(i+1, _t+3*w*ts[i].d) + ts[i].v) {
            ans.push_back(i);
            build(i+1, _t+3*w*ts[i].d);
            return;
        }
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int dumdum = 0;
    while(cin >> t >> w >> n) {
        if(dumdum) cout << '\n';
        dumdum++;
        ans.clear();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++)
            cin >> ts[i].d >> ts[i].v;
        cout << solve(0, 0) << '\n';
        build(0, 0);
        cout << (int)ans.size() << '\n';
        for(int i : ans)
            cout << ts[i].d << ' ' << ts[i].v << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
