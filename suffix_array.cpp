vll suffix_array(string& s){
    ll n=s.size();
    vll ans(n),r(n),tmp(n);
    iota(all(ans),0ll);
    copy(all(s),r.begin());
    for(ll k=1;k<n;k*=2){
        auto cmp=[&](ll i,ll j){
            if(r[i]!=r[j])return r[i]<r[j];
            ll ri=(i+k<n)?r[i+k]:-1;
            ll rj=(j+k<n)?r[j+k]:-1;
            return ri<rj;
        };
        sort(all(ans),cmp);
        tmp[ans[0]]=0;
        lp(i,1,n)tmp[ans[i]]=tmp[ans[i-1]]+cmp(ans[i-1],ans[i]);
        r=tmp;
    }
    return ans;
}
vll kasai_lcp_suffix(string& s,vll& p){
    ll n=s.size(),k=0;
    vll rank(n,0),lcp(n-1,0);
    lp(i,0,n)rank[p[i]]=i;
    lp(i,0,n){
        if(rank[i]==n-1){k=0;continue;}
        ll j=p[rank[i]+1];
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
        lcp[rank[i]]=k;
        if(k)k--;
    }
    return lcp;
}