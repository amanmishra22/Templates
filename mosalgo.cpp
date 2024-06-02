#include<bits/stdc++.h>
 #define ll long long int
 #define lp(i,a,b) for(ll i=a;i<b;i++)
 #define lpa(i,a,b,x) for(ll i=a;i<b;i+=x)
 #define pl(i,a,b) for(ll i=a;i>=b;i--)
 #define eb push_back
 #define ms(a,x) memset(a,x,sizeof(a))
 #define all(v) v.begin(),v.end()
 #define pll pair<ll,ll>
 #define vpll vector<pll>
 #define vll vector<ll>
 #define vvll vector<vll>
 #define yes cout<<"YES\n";
 #define no cout<<"NO\n";
 #define ff first
 #define ss second
 const ll mod1= 1000000007;
 const ll mod2= 998244353;
 const ll INF= 5000000000000000000;
 const ll INM= -5000000000000000000;
 using namespace std;
 const ll rootN=555;
 ll freq[200005],a[200005];
 ll dis;
 inline ll gilbertOrder(ll x,ll y,ll pow,ll rotate) {
  if(pow==0)return 0;
  ll hpow=1<<(pow-1);
  ll seg=(x<hpow)?((y<hpow)?0:3):((y<hpow)?1:2);
  seg=(seg + rotate)&3;
  const int rotateDelta[4]={3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  ll subSquareSize = 1ll << (2*pow - 2);
  ll ans = seg * subSquareSize;
  ll add = gilbertOrder(nx, ny, pow-1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}
 struct query{
   ll l,r,qnum,blocknum;
 }; 
 inline bool operator<(const query &a, const query &b) {
  return a.blocknum < b.blocknum;
}
 void add(ll& x){
   if(!freq[x])dis++;
   freq[x]++;
 }
 void remove(ll& x){
   freq[x]--;
   if(!freq[x])dis--;
 }
 void adjust(ll& curl,ll& curr,query& q){
   while(curl>q.l)curl--,add(a[curl]);
   while(curr<q.r)curr++,add(a[curr]);
   while(curl<q.l)remove(a[curl]),curl++;
   while(curr>q.r)remove(a[curr]),curr--;
 }
 void solve()
 {
    ll n,com=1,q;cin>>n>>q;
    map<ll,ll>m;
    lp(i,0,n){
      cin>>a[i];
      if(m.find(a[i])!=m.end())a[i]=m[a[i]];
      else m[a[i]]=com,a[i]=com++;
    }
    ll ans[q];
    vector<query>queries(q);
    lp(i,0,q){
      ll x,y;cin>>x>>y;
      x--;y--;
      queries[i].l=x;
      queries[i].r=y;
      queries[i].qnum=i;
      queries[i].blocknum=gilbertOrder(x,y,21,0);
    }
    sort(all(queries));
    dis=1;
    ll curl=queries[0].l,curr=queries[0].l;
    freq[a[curl]]++;
    for(auto i:queries){
      adjust(curl,curr,i);
      ans[i.qnum]=dis;
    }
    for(auto i:ans)cout<<i<<"\n";
 }
 int main() 
 {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll t=1;
   //cin>>t;
   lp(i,1,t+1)solve();
 }