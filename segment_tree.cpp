template<typename T>
class Segtree{
    public:
    vector<T>seg;
    ll n;
    T comp(T a,T b){
       return max(a,b);
    }
    Segtree(ll n,ll a[]){
       this->n=n;
       seg.resize(4*n+5);
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
    void update(ll ind,ll val,ll l,ll r,ll p){
        if(l==r){
            seg[p]=val;
            return;
        }
        ll m=(l+r)/2;
        if(ind<=m)update(ind,val,l,m,2*p+1);
        else update(ind,val,m+1,r,2*p+2);
        seg[p]=comp(seg[2*p+1],seg[2*p+2]);
    }
    T query(ll ql,ll qr,ll l,ll r,ll p){
       if(ql<=l&&r<=qr)return seg[p];
       if(r<ql||qr<l)return INM;
       ll m=(l+r)/2;
       return comp(query(ql,qr,l,m,2*p+1),query(ql,qr,m+1,r,2*p+2));
    }
};