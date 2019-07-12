//-Modular exponent( B^P MOD M ): #O(LOG(P))
unsigned int mod_pow(unsigned int b, unsigned int p , unsigned int m){
    if(p == 0)
        return 1;
    else if(p == 1)
        return b%m;
    else if(p%2 == 0){
        unsigned int x = mod_pow(b, p/2, m) % m;
        return (x*x)%m;
    }
    else{
        return ((b%m) * mod_pow(b, p-1, m)) % m;
    }
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