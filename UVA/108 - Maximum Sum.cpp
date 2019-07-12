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
const int N = 1e2 + 5;

int n;
int grid[N][N];
int sum[N]; // long long for large values

// long long for large values
int kadane2D()
{
    int mx = -1e9;
    for(int j1=0; j1<n; ++j1) {
        fill(sum, sum+n, 0);
        for(int j2=j1; j2<n; ++j2) {
            for(int i=0; i<n; ++i)
                sum[i] += grid[j2][i];
            int tmp = sum[0];
            mx = max(mx, tmp);
            for(int i=1; i<n; ++i) {
                tmp = max(sum[i], tmp + sum[i]);
                mx = max(mx, tmp);
            }
        }
    }
    return mx;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];
    cout << kadane2D() << '\n';
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
