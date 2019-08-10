const int N = 1e5 + 2;

int n;
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

// example
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    build(1, 0, n-1);
    update(1, 0, n-1, 2, 13);
    while(true) {
        int l, r; cin >> l >> r;
        cout << sum(1, 0, n-1, l, r) << endl;
    }
    return 0;
}