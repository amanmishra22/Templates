class Trie{
  public:
  Trie* child[26];
  ll complete;
  Trie(){
    lp(i,0,26)child[i]=NULL;
    complete=0;
  }
  void insert(string& s){
    Trie* cur=this;
    for(auto i:s){
      if(cur->child[i-'a']==NULL)cur->child[i-'a']=new Trie();
      cur=cur->child[i-'a'];
    }
    cur->complete++;
  }
  bool ispresent(string& s){
    Trie* cur=this;
    for(auto i:s){
      if(cur->child[i-'a']==NULL)return false;
      cur=cur->child[i-'a'];
    }
    return (cur!=NULL&&(cur->complete>0));
  }
  bool isempty(Trie* node){
    lp(i,0,26)if(node->child[i])return false;
    return true;
  }
  void remove(string& s){
     Trie* cur=this;
     del(cur,s,0);
  }
  void del(Trie* &cur,string& s,ll dep=0){
     if(!cur)return;
     if(dep==s.size()){
      if(cur->complete)cur->complete--;
      if(isempty(cur)&&cur->complete==0){
        delete(cur);
        cur=NULL;
      }
      return;
     }
     del(cur->child[s[dep]-'a'],s,dep+1);
     if(isempty(cur)&&cur->complete==0&&dep!=0){
      delete(cur);
      cur=NULL;
     }
     return;
  }
};