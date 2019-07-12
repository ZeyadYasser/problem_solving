#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
#define x first
#define y second

void fastInOut();

const int N = 1e3 + 5;

int r, c;

vector<pii> bombs;
bool grid[N][N];

pii src, dst;
int dist[N][N];
int vid = 1;
short vis[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<pii> Q;
    Q.push(src);
    dist[src.x][src.y] = 0;
    vis[src.x][src.y] = vid;
    while(!Q.empty()) {
        pii u = Q.front();
        Q.pop();

        if(u == dst)
            return dist[u.x][u.y];

        for(int i=0; i<4; i++) {
            pii v = {u.x+dx[i], u.y+dy[i]};
            if(vis[v.x][v.y] == vid)
                continue;
            if(v.x < 0 || v.x >= r || v.y < 0 || v.y >= c)
                continue;
            if(grid[v.x][v.y])
                continue;
            Q.push(v);
            dist[v.x][v.y] = dist[u.x][u.y] + 1;
            vis[v.x][v.y] = vid;
        }
    }
    return 0;
}

void clear()
{
    vid++;
    for(pii p : bombs)
        grid[p.x][p.y] = 0;
    bombs.clear();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    while(true) {
        cin >> r >> c;
        if(r == 0 && c == 0)
            return 0;
        clear();
        int n; cin >> n;
        while(n--) {
            int ri, ni;
            cin >> ri >> ni;
            for(int i=0; i<ni; i++) {
                int ci; cin >> ci;
                grid[ri][ci] = 1;
                bombs.push_back({ri, ci});
            }
        }
        cin >> src.x >> src.y;
        cin >> dst.x >> dst.y;
        cout << bfs() << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
