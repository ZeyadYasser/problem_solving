const int N = 1e2 + 5;

int n;
int grid[N][N];
int sum[N]; // long long for large values

// long long for large values
int kadane2D() // max sub-rectangle
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
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];
    cout << kadane2D() << '\n';
    return 0;
}

