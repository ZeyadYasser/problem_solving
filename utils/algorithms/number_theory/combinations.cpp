const int N  = 1e5;
const ll MOD = 1e9 + 7;

ll fact[2*N];

ll mod_exp(ll k, ll p)
{
    if(p == 0) return 1;
    if(p == 1) return k;
    if(p&1) {
        return ((k % MOD) * (mod_exp(k, p-1))) % MOD;
    } else {
        ll t = mod_exp(k, p/2);
        return (t*t) % MOD;
    }
}

// mod must be prime
ll C_mod(ll n, ll k)
{
    return (((fact[n] * mod_exp(fact[k], MOD-2)) % MOD) * mod_exp(fact[n-k], MOD-2)) % MOD;
}

main()
{
    /*pre-compute factorial*/
    fact[0] = 1;
    for(ll i=1; i<2*N; ++i)
        fact[i] = (fact[i-1]*i) % MOD;
}