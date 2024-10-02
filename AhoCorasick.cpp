class ahocorasick{
    public:
    struct Node {
        Node* child[26];  
        Node* suffixLink;           
        Node* outputLink;           
        ll pattern_ind;               
        Node():suffixLink(nullptr),outputLink(nullptr),pattern_ind(-1){
            fill(child,child +26,nullptr);  
        }
    };
    Node* root;
    ll n;
    ahocorasick(){
        root =new Node();
        n=0;
    }
    void insert(string& s,ll ind){
        Node* cur=root;
        for(auto i:s){
           if(cur->child[i-'a']==nullptr)cur->child[i-'a']=new Node();
           cur=cur->child[i-'a']; 
        }
        cur->pattern_ind=ind;
        n=max(n,ind+1);
    }
    void build(){
        root->suffixLink=root;
        queue<Node*>q;
        lp(i,0,26){
            if(root->child[i]){
                root->child[i]->suffixLink=root;
                q.push(root->child[i]);
            }
        }
        while(q.size()){
            Node* cur=q.front();
            q.pop();
            lp(i,0,26){
                if(cur->child[i]){
                    Node* ch=cur->child[i];
                    Node* f=cur->suffixLink;
                    while(!f->child[i]&&f!=root)f=f->suffixLink;
                    if(f->child[i])ch->suffixLink=f->child[i];
                    else ch->suffixLink=root;
                    q.push(ch);
                }
            }
            if(cur->suffixLink->pattern_ind>=0)cur->outputLink=cur->suffixLink;
            else cur->outputLink=cur->suffixLink->outputLink;
        }
    }
    vvll search(string& txt){
        vvll ans(n);
        Node* par=root;
        lp(i,0,txt.size()){
            if(par->child[txt[i]-'a']){
                par=par->child[txt[i]-'a'];
                if(par->pattern_ind>-1)ans[par->pattern_ind].eb(i);
                Node* mol=par->outputLink;
                while(mol!=nullptr){
                    ans[mol->pattern_ind].eb(i);
                    mol=mol->outputLink;
                }
            }
            else{
                while(par!=root&&par->child[txt[i]-'a']==nullptr)par=par->suffixLink;
                if(par->child[txt[i]-'a'])i--;
            }
        }
        return ans;
    }
};