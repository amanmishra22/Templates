class dsu{
  public:
  vll par,rank;
  dsu(ll n){
    par.resize(n+1);
    rank.resize(n+1);
    iota(all(par),0);
    lp(i,0,n+1)rank[i]=1;
  }
  ll find(ll x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  void merge(ll u,ll v){
     ll p1=find(u),p2=find(v);
     if(p1!=p2){
        if(rank[p1]<rank[p2])par[p1]=p2;
        else {
            par[p2]=p1;
            if(rank[p1]==rank[p2])rank[p1]++;
        }
     }
  }
};