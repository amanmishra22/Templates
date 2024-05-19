class lcat{
    public:
    ll n,l;
    vvll adj,up;
    vll dep;
    lcat(ll n,ll root,vvll& adj):n(n+1),adj(adj){
       dep.assign(n+1,0);
       l=ceil(log2(n));
       up.assign(n+1,vll(l+1));
       dfs(root,root);
    }
    void dfs(ll node,ll par){
        up[node][0]=par;
        lp(i,1,l+1)up[node][i]=up[up[node][i-1]][i-1];
        for(auto i:adj[node]){
            if(i==par)continue;
            dep[i]=dep[node]+1;
            dfs(i,node);
        }
    }
    ll lca(ll u,ll v){
         if(dep[u]<dep[v])swap(u,v);
         pl(i,l,0){
            if(dep[u]-dep[v]>=(1<<i))u=up[u][i];
         }
         if(u==v)return u;
         pl(i,l,0){
            if(up[u][i]!=up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
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