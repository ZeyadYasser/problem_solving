// long long
int gcd(int a, int b, int & x, int & y)
{
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// a and m must be co-prime gcd(a, m) = 1
int inv_mod(int a, int m)
{
	int x, y;
	int g = gcd(a, m, x, y);
	return (g == 1) ? (x % m + m) % m : -1;
}

// if MOD is **PRIME**
int mod_exp(int k, int p, int mod)
{
    if(p == 0) return 1;
    if(p == 1) return k;
    if(p&1) {
        return ((k % mod) * (mod_exp(k, p-1, mod))) % mod;
    } else {
        int t = mod_exp(k, p/2, mod);
        return (t*t) % mod;
    }
}

int inv_mod(int a, int m)
{
	return mod_exp(a, m-2);
}
