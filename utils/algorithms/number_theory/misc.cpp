//-Modular exponent( k^p MOD mod ): #O(LOG(P))
ll mod_exp(ll k, ll p, ll mod)
{
    if(p == 0) return 1;
    if(p == 1) return k;
    if(p&1) {
        return ((k % mod) * (mod_exp(k, p-1, mod))) % mod;
    } else {
        ll t = mod_exp(k, p/2, mod);
        return (t*t) % mod;
    }
}

bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < iter; i++) {
        int a = 2 + rng() % (n - 3);
        if (mod_exp(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

//-Huge Modular exponent( a^(b^c) MOD mod ): #O(LOG(P))
ll huge_mod_exp(ll a, ll b, ll c, ll mod)
{
    return mod_exp(a, mod_exp(b, c, mod - 1), mod);
}

//-Newton’s method(finds roots of any fn. easily):
double func(double x){
    return x*x; // x^2 example function
}
double diff_func(double x){
    return 2*x; // function derivative
}
// vector values are seeds for roots LOL
vector<double> newton_method(vector<double> values, double abs_err){
    // abs_err specifies accepted error
    for(int i=0; i<values.size(); i++){
        while(abs(func(values[i])) > abs_err){
            values[i] = values[i] - (func(values[i])/diff_func(values[i]));
        }
    }
    return values;
}
