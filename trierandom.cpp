class Trie{
  public:
  map<char,Trie*>child;
  bool complete;
  Trie(){
    child.clear();
    complete=false;
  }
  void insert(string& s){
    Trie* cur=this;
    for(auto i:s){
      if(cur->child[i]==NULL)cur->child[i]=new Trie();
      cur=cur->child[i];
    }
    cur->complete=true;
  }
  bool ispresent(string& s){
    Trie* cur=this;
    for(auto i:s){
      if(cur->child[i]==NULL)return false;
      cur=cur->child[i];
    }
    return (cur!=NULL&&cur->complete);
  }
  bool isempty(Trie* node){
    for(auto i:node->child)if(i.ss)return false;
    return true;
  }
  void remove(string& s){
     Trie* cur=this;
     del(cur,s,0);
  }
  void del(Trie* &cur,string& s,ll dep=0){
     if(!cur)return;
     if(dep==s.size()){
      if(cur->complete)cur->complete=false;
      if(isempty(cur)){
        delete(cur);
        cur=NULL;
      }
      return;
     }
     del(cur->child[s[dep]],s,dep+1);
     if(isempty(cur)&&cur->complete==false&&dep!=0){
      delete(cur);
      cur=NULL;
     }
     return;
  }
};