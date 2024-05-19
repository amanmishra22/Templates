template<typename T>
class lazytree{
    public:
    vector<T>seg,lazy;
    ll n;
    T comp(T a,T b){
       return a+b;
    }
    lazytree(ll n,ll a[]){
       this->n=n;
       seg.resize(4*n+5);
       lazy.resize(4*n+5);
       build(a,0,n-1,0);
    }
    void build(ll a[],ll l,ll r,ll p){
        if(l==r){
            seg[p]=a[l];
            return;
        }
        ll m=(l+r)/2;
        build(a,l,m,2*p+1);
        build(a,m+1,r,2*p+2);
        seg[p]=comp(seg[2*p+1],seg[2*p+2]);
    }
    void update(ll ql,ll qr,ll val,ll l,ll r,ll p){
        if(lazy[p]!=0){
            seg[p]+=(r-l+1)*lazy[p];
            if(l!=r){
                lazy[2*p+1]+=lazy[p];
                lazy[2*p+2]+=lazy[p];
            }
            lazy[p]=0;
        }
        if(qr<l||ql>r)return;
        if(ql<=l&&qr>=r){
            seg[p]+=(r-l+1)*val;
            if(l!=r){
                lazy[2*p+1]+=val;
                lazy[2*p+2]+=val;
            }
            return;
        }
        ll m=(l+r)/2;
        update(ql,qr,val,l,m,2*p+1);
        update(ql,qr,val,m+1,r,2*p+2);
        seg[p]=comp(seg[2*p+1],seg[2*p+2]);
    }
    T query(ll ql,ll qr,ll l,ll r,ll p){
       if(lazy[p]!=0){
        seg[p]+=(r-l+1)*lazy[p];
        if(l!=r){
            lazy[2*p+1]+=lazy[p];
            lazy[2*p+2]+=lazy[p];
        }
        lazy[p]=0;
       }
       if(ql<=l&&r<=qr)return seg[p];
       if(r<ql||qr<l)return 0;
       ll m=(l+r)/2;
       return comp(query(ql,qr,l,m,2*p+1),query(ql,qr,m+1,r,2*p+2));
    }
};