#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
// change type to pair & use counter for multi-set
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

void fastInOut();
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int a[N]; // array of values
int t[4*N];

void build(int v, int l, int r)
{
    if(l == r)
        t[v] = a[l];
    else {
        int m = (r + l) / 2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v] = t[2*v] + t[2*v+1];
    }
}

// root, (lt, rt) boundries, (l, r) query range
int sum(int v, int lt, int rt, int l, int r)
{
    if(r < l)
        return 0;
    if(lt == l && rt == r)
        return t[v];

    int mt = (rt + lt) / 2;
    return sum(2*v, lt, mt, l, min(r, mt)) +
           sum(2*v+1, mt+1, rt, max(l, mt+1), r);
}

void update(int v, int lt, int rt, int pos, int val)
{
    if(lt == rt)
        t[v] = val;
    else {
        int mt = (rt + lt) / 2;
        if(pos <= mt)
            update(2*v, lt, mt, pos, val);
        else
            update(2*v+1, mt+1, rt, pos, val);
        t[v] = t[2*v] + t[2*v+1];
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int n; int T = 1;
    cin >> n;
    while(true) {
        if(n == 0) return 0;
        for(int i=1; i<=n; ++i)
            cin >> a[i];
        build(1, 1, n);
        cout << "Case " << T++ << ":\n";
        string query;
        while(cin >> query) {
            if(query == "END") break;
            if(query == "S") {
                int pos, val;
                cin >> pos >> val;
                update(1, 1, n, pos, val);
            } else {
                int l, r;
                cin >> l >> r;
                cout << sum(1, 1, n, l, r) << '\n';
            }
        }
        cin >> n;
        if(n) cout << '\n';
    }
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
