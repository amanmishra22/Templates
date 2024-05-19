class hldclass{
    public:
    vll parent,depth,heavy,head,pos,val,hldval;
    ll n,curpos;
    vvll adj;
    hldclass(ll n,ll root,vvll& adj,vll& a):n(n),adj(adj),val(a){
       parent.resize(n+1);
       depth.assign(n+1,0);
       heavy.assign(n+1,-1);
       head.resize(n+1);
       pos.resize(n+1);
       hldval.resize(n);
       parent[root]=n;
       parent[n]=n;
       head[n]=n;
       curpos=0;
       dfs(root);
       decompose(root,root);
    }
    ll dfs(ll node){
        ll sz=1,mxsz=0;
        for(auto i:adj[node]){
            if(i!=parent[node]){
                parent[i]=node,depth[i]=depth[node]+1;
                ll tmp=dfs(i);
                sz+=tmp;
                if(tmp>mxsz)mxsz=tmp,heavy[node]=i;
            }
        }
        return sz;
    }
    void decompose(ll node,ll h){
        head[node]=h,pos[node]=curpos,hldval[curpos]=val[node];
        curpos++;
        if(heavy[node]!=-1)decompose(heavy[node],h);
        for(auto i:adj[node]){
            if(i!=parent[node]&&i!=heavy[node])decompose(i,i);
        }
    }
};