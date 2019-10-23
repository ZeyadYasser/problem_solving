
int ternary()
{
    int st = 0, ed = n;
    while(ed - st > 1) {
        int mid = (st + ed) >> 1;
        if(prob(mid) < prob(mid+1))
            st = mid;
        else
            ed = mid;
    }
    return st + 1;
}

