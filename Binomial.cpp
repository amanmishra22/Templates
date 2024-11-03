class Binomial{
public:
    vector<ll>fact,factInv,numInv;
    ll n,mod;
    Binomial(){
        this->n=0;
        this->mod=1000000007;
    }
    Binomial(ll n,ll mod){
        this->n=n;
        this->mod=mod;
        fact.assign(n+1,0);
        factInv.assign(n+1,0);
        numInv.assign(n+1,0);
        inverseOfNumber();
        inverseOfFactorial();
        factorial();
    }
    ll modMul(ll a,ll b){
        return (a%mod*b%mod)%mod;
    }
    void inverseOfNumber(){
        numInv[0]=numInv[1]=1;
        for(ll i=2;i<=n;i++)numInv[i]=modMul(numInv[mod%i],mod-mod/i);
    }
    void inverseOfFactorial(){
        factInv[0]=factInv[1]=1;
        for(ll i=2;i<=n;i++)factInv[i]=modMul(numInv[i],factInv[i-1]);
    }
    void factorial(){
        fact[0]=1;
        for(ll i=1;i<=n;i++)fact[i]=modMul(fact[i-1],i);
    }
    ll ncr(int n,int r){
        ll ans=modMul(fact[n],modMul(factInv[r],factInv[n-r]));
        return ans;
    }
};