class dsu{
  public:
  ll n;
  vll par,rank,s,mn,mx;
  dsu(ll n){
    this->n=n;
    par.resize(n+1);
    rank.resize(n+1);
    s.resize(n+1);
    mn.resize(n+1);
    mx.resize(n+1);
    iota(all(par),0);
    iota(all(mn),0);
    iota(all(mx),0);
    lp(i,0,n+1)rank[i]=s[i]=1;
  }
  ll find(ll x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  void merge(ll u,ll v){
     ll p1=find(u),p2=find(v);
     if(p1!=p2){
        if(rank[p1]<rank[p2]){
            mn[p2]=min(mn[p2],mn[p1]);
            mx[p2]=max(mx[p2],mx[p1]);
            s[p2]+=s[p1];
            par[p1]=p2;
        }
        else {
            mn[p1]=min(mn[p2],mn[p1]);
            mx[p1]=max(mx[p2],mx[p1]);
            s[p1]+=s[p2];
            par[p2]=p1;
            if(rank[p1]==rank[p2])rank[p1]++;
        }
     }
  }
};