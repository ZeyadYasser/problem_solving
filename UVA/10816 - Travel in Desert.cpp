///// WRONG ANSWER /////
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
const double EPS = 1e-7;
const int N = 1e2 + 5;

struct node {
    int idx;
    long double R, D;
};

int n, e, s, t;
vector<node> G[N];

long double dist[N], temp[N];
int vid = 1;
int vis[N], p[N];

void clear()
{
    vid++;
    fill(dist, dist + n, (double)1e9);
    fill(temp, temp + n, (double)1e9);
    fill(p, p + n, -1);
    for(int i=0; i<n; i++)
        G[i].clear();
}

long double min_temp()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    temp[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        if(vis[u.y] == vid)
            continue;
        vis[u.y] = vid;
        for(node to : G[u.y]) {
            if(max(temp[u.y], to.R) + EPS < temp[to.idx]) {
                temp[to.idx] = max(temp[u.y], to.R);
                pq.push({temp[to.idx], to.idx});
            }
        }
    }
    return temp[t];
}

void min_dist()
{
    long double mn_temp = min_temp();
    vid++;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        if(vis[u.y] == vid)
            continue;
        vis[u.y] = vid;
        for(node to : G[u.y]) {
            if(max(temp[u.y], to.R) <= mn_temp && (dist[u.y] + to.D) + EPS < dist[to.idx]) {
                dist[to.idx] = dist[u.y] + to.D;
                p[to.idx] = u.y;
                pq.push({dist[to.idx], to.idx});
            }
        }
    }
}

void print(int nd)
{
    if(nd == -1)
        return;
    print(p[nd]);
    cout << nd + 1;
    if(nd != t) cout << ' ';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    while(cin >> n) {
        cin >> e >> s >> t;
        s--; t--;
        clear();
        while(e--) {
            int u, v;
            node nd;
            cin >> u >> v >> nd.R >> nd.D;
            u--; v--;
            nd.idx = u;
            G[v].push_back(nd);
            nd.idx = v;
            G[u].push_back(nd);
        }
        min_dist();
        print(t); cout << '\n';
        cout << fixed << setprecision(1)
             << dist[t] << ' ' << temp[t] << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
