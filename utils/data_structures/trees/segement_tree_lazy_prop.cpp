#define left(v) v<<1
#define right(v) v<<1 | 1
 
int n, q;
int A[N];
int fib[35];
 
struct node
{
    int num, mn, lazy, sum;
};
 
node t[4*N];
int diff_cache[M];
 
int fib_diff(int num)
{
    for(int i=0; i<35; ++i) {
        if(num <= fib[i])
            return fib[i] - num;
    }
}
 
void update_node(int v)
{
    t[v].sum = t[left(v)].sum + t[right(v)].sum;
    t[v].mn = min(t[left(v)].mn - t[left(v)].lazy, t[right(v)].mn - t[right(v)].lazy);
}
 
void build(int v, int l, int r)
{
    if(l == r) {
        t[v].mn = diff_cache[A[l]];
        t[v].lazy = 0;
        t[v].sum = (t[v].mn == 0) ? 1 : 0;
        t[v].num = A[l];
    } else {
        int m = (r + l) >> 1;
        build(left(v), l, m);
        build(right(v), m+1, r);
        t[v].lazy = 0;
        update_node(v);
        t[v].num = -1;
    }
}
 
void push(int v)
{
    t[left(v)].lazy += t[v].lazy;
    t[right(v)].lazy += t[v].lazy;
    t[v].lazy = 0;
}
 
void flush(int v)
{
    if(t[v].num != -1) { // leaf
        t[v].num += t[v].lazy;
        t[v].lazy = 0;
        t[v].mn = diff_cache[t[v].num];
        t[v].sum = (t[v].mn == 0) ? 1 : 0;
    } else if(t[v].lazy && t[v].lazy >= t[v].mn) {
        push(v);
        if(t[left(v)].lazy && t[left(v)].lazy >= t[left(v)].mn)
            flush(left(v));
        if(t[right(v)].lazy && t[right(v)].lazy >= t[right(v)].mn)
            flush(right(v));
 
        update_node(v);
    }
}
 
void update(int v, int lt, int rt, int l, int r, int val)
{
    if(l > r)
        return;
    if(l == lt && r == rt) {
        t[v].lazy += val;
        flush(v);
    } else {
        push(v);
        int m = (lt + rt) >> 1;
 
        update(left(v), lt, m, l, min(r, m), val);
        update(right(v), m+1, rt, max(l, m+1), r, val);
 
        update_node(v);
    }
}
 
int query(int v, int lt, int rt, int l, int r)
{
    if(l > r)
        return 0;
    flush(v);
    if(l <= lt && r >= rt)
        return t[v].sum;
    int m = (lt + rt) >> 1;
    return query(left(v), lt, m, l, min(r, m)) +
           query(right(v), m+1, rt, max(l, m+1), r);
}