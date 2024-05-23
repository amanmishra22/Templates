/*
zero Indexed
we have vars variables
F=(x_0 XXX y_0) and (x_1 XXX y_1) and ... (x_{vars-1} XXX y_{vars-1})
here {x_i,y_i} are variables
and XXX belongs to {OR,XOR}
is there any assignment of variables such that F=true
*/
class twosat{
    public:
    ll n;
    vvll g,gt;
    vector<bool>vis,res;
    vll comp;
    stack<ll>ts;
    twosat(ll var=0){
       n=var<<1;
       g.resize(n);
       gt.resize(n);
    }
    //zero indexed, be careful
  //if you want to force variable a to be true in OR or XOR combination
  //add addOR (a,1,a,1);
  //if you want to force variable a to be false in OR or XOR combination
  //add addOR (a,0,a,0);

  //(x_a or (not x_b))-> af=1,bf=0
    void addor(ll a,bool af,ll b,bool bf){
        a+=a+(af^1);
        b+=b+(bf^1);
        g[a^1].eb(b); // !a => b
        g[b^1].eb(a);  // !b => a
        gt[a].eb(b^1);
        gt[b].eb(a^1);
    }
    //(!x_a xor !x_b)-> af=0, bf=0
    void addxor(ll a,bool af,ll b,bool bf){
        addor(a,af,b,bf);
        addor(a,!af,b,!bf);
    }
     //add this type of condition->
  //add(a,af,b,bf) means if a is af then b must need to be bf
    void _add(ll a,bool af,ll b,bool bf){
        a+=a+(af^1);
        b+=b+(bf^1);
        g[a].eb(b);
        gt[b].eb(a);
    }
    void add(ll a,bool af,ll b,bool bf){
        _add(a,af,b,bf);
        _add(b,!bf,a,!af);
    }
    void dfs1(ll u){
        vis[u]=true;
        for(auto v:g[u])if(!vis[v])dfs1(v);
        ts.push(u);
    }
    void dfs2(ll u,ll c){
        comp[u]=c;
        for(auto v:gt[u])if(comp[v]==-1)dfs2(v,c);
    }
    bool ok(){
        vis.resize(n,false);
        lp(i,0,n)if(!vis[i])dfs1(i);
        ll scc=0;
        comp.resize(n,-1);
        while(ts.size()){
          ll u=ts.top();
          ts.pop();
          if(comp[u]==-1)dfs2(u,scc++);
        }
        res.resize(n/2);
        lpa(i,0,n,2){
            if(comp[i]==comp[i+1])return false;
            res[i/2]=(comp[i]>comp[i+1]);
        }
        return true;
    }
};