void cnt_sort(vll& p,vll& c){
    ll n=p.size();
    vll cnt(n,0),pnew(n),pos(n,0);
    lp(i,0,n)cnt[c[i]]++;
    lp(i,1,n)pos[i]+=pos[i-1]+cnt[i-1];
    lp(i,0,n){
        ll x=c[p[i]];
        pnew[pos[x]]=p[i];
        pos[x]++;
    }
    p.swap(pnew);
}
vll suffix_array(string& s){
    ll n=s.size(),k=0;
    vll p(n),c(n);
    vpll v(n);
    lp(i,0,n)v[i]={s[i],i};
    sort(all(v));
    lp(i,0,n)p[i]=v[i].ss;
    c[p[0]]=0;
    lp(i,1,n)c[p[i]]=c[p[i-1]]+(v[i].ff!=v[i-1].ff);
    while((1ll<<k)<n){
      lp(i,0,n)p[i]=(p[i]-(1ll<<k)+n)%n;
      cnt_sort(p,c);
      vll cnew(n);
      cnew[p[0]]=0;
      lp(i,1,n){
        pll prev={c[p[i-1]],c[(p[i-1]+(1ll<<k))%n]};
        pll now={c[p[i]],c[(p[i]+(1ll<<k))%n]};
        if(prev==now)cnew[p[i]]=cnew[p[i-1]];
        else cnew[p[i]]=cnew[p[i-1]]+1;
      }
      c.swap(cnew);
      k++;
    }
    return p;
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