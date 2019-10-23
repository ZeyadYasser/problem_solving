#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
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
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
	
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
