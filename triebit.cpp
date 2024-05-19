class Trie{
  public:
  Trie* child[2];
  ll complete;
  Trie(){
    child[0]=child[1]=NULL;
    complete=0;
  }
  void insert(ll n){
    Trie* cur=this;
    pl(i,40,0){
      ll msk=(n>>i)&1;
      if(cur->child[msk]==NULL)cur->child[msk]=new Trie();
      cur=cur->child[msk];
    }
    cur->complete++;
  }
  bool ispresent(ll n){
    Trie* cur=this;
    pl(i,40,0){
        ll msk=(n>>i)&1;
        if(cur->child[msk]==NULL)return false;
        cur=cur->child[msk];
    }
    return (cur!=NULL&&(cur->complete>0));
  }
  bool isempty(Trie* node){
    if(node->child[0]||node->child[1])return false;
    return true;
  }
  void remove(ll n){
     Trie* cur=this;
     del(cur,n,40);
  }
  void del(Trie* &cur,ll n,ll d=40){
     if(!cur)return;
     if(d==-1){
      if(cur->complete)cur->complete--;
      if(cur->complete==0&&isempty(cur)){
        delete(cur);
        cur=NULL;
      }
      return;
     }
     del(cur->child[(n>>d)&1],n,d-1);
     if(isempty(cur)&&cur->complete==0&&d!=40){
      delete(cur);
      cur=NULL;
     }
     return;
  }
};
ll fun(Trie* node,ll val){
    ll ans=0;
    pl(i,40,0){
      ll msk=(val>>i)&1;
      ll req=1-msk;
      if(node->child[req]){
        ans+=(1ll<<i);
        node=node->child[req];
      }
      else node=node->child[msk];
    }
    return ans;
}