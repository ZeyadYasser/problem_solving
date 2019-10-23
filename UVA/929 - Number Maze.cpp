#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
#define x first
#define y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fastInOut();

const int N = 1e3 + 5;

int r, c;
int maze[N][N];

int vid = 1;
int vis[N][N];
int dist[N][N];

int conv(int i, int j)
{
    return i*r + j;
}

int dijkstra() {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({maze[0][0], {0, 0}});
    dist[0][0] = maze[0][0];
    while(!pq.empty()) {
        pii u = pq.top().y;
        pq.pop();
        if(vis[u.x][u.y] == vid)
            continue;
        vis[u.x][u.y] = vid;
        for(int i=0; i<4; i++) {
            pii to = {u.x+dx[i], u.y+dy[i]};
            if(to.x < 0 || to.x >= r || to.y < 0 || to.y >= c)
                continue;
            if(dist[u.x][u.y] + maze[to.x][to.y] < dist[to.x][to.y]) {
                dist[to.x][to.y] = dist[u.x][u.y] + maze[to.x][to.y];
                pq.push({dist[to.x][to.y], to});
            }
        }
    }
    return dist[r-1][c-1];
}

void clear() {
    memset(dist, 0x7f, sizeof(dist));
    vid++;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        cin >> r >> c;
        clear();
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> maze[i][j];
        cout << dijkstra() << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
