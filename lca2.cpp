class lcat{
    public:
    ll n,l,timer;
    vvll adj,up;
    vll tin,tout,dep;
    lcat(ll n,ll root,vvll& adj){
       this->n=n+1;
       this->adj=adj;
       tin.resize(n+1);
       tout.resize(n+1);
       dep.assign(n+1,0);
       timer=0;
       l=ceil(log2(n));
       up.assign(n+1,vll(l+1));
       dfs(root,root);
    }
    void dfs(ll node,ll par){
        tin[node]=++timer;
        up[node][0]=par;
        lp(i,1,l+1)up[node][i]=up[up[node][i-1]][i-1];
        for(auto i:adj[node]){
            if(i==par)continue;
            dep[i]=dep[node]+1;
            dfs(i,node);
        }
        tout[node]=++timer;
    }
    bool is_ancestor(ll u,ll v){
        return tin[u]<=tin[v]&&tout[u]>=tout[v];
    }
    ll lca(ll u,ll v){
        if(is_ancestor(u,v))return u;
        if(is_ancestor(v,u))return v;
        pl(i,l,0){
            if(!is_ancestor(up[u][i],v))u=up[u][i];
        }
        return up[u][0];
    }
    ll kth_ancestor(ll u,ll k){
        lp(i,0,l+1){
            if((k>>i)&1)u=up[u][i];
        }
        return u;
    }
    ll distance(ll u,ll v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
};