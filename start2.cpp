#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define lpa(i,a,b,x) for(ll i=a;i<b;i+=x)
#define pl(i,a,b) for(ll i=a;i>=b;i--)
#define sb(x) __builtin_popcountll(x)
#define lz(x) __builtin_clzll(x)
#define tz(x) __builtin_ctzll(x)
#define eb push_back
#define all(v) v.begin(),v.end()
#define ubv(v,a) upper_bound(all(v),a)
#define lbv(v,a) lower_bound(all(v),a)
#define bsv(v,a) binary_search(all(v),a)
#define uba(a,n,c) upper_bound(a,a+n,c)
#define lba(a,n,c) lower_bound(a,a+n,c)
#define bsa(a,n,c) binary_search(a,a+n,c)
#define ms(a,x) memset(a,x,sizeof(a))
#define si(i,s) for(set<ll>::iterator i=s.begin();i!=s.end();i++)
#define sp(n,a) cout<<fixed<<setprecision(n)<<a
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define aca(a,n,x) accumulate(a,a+n,x)
#define ca(a,n,x) count(a,a+n,x)
#define fi(a,n,x) find(a,a+n,x)-a
#define ap(s) do{cout<<s<<endl;}while(next_permutation(all(s)))
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define disa(a,n) lp(i,0,n)cout<<a[i]<<" ";cout<<"\n";
#define disv(v) lp(i,0,v.size())cout<<v[i]<<" ";cout<<"\n";
#define ff first
#define ss second
const ll mod1= 1000000007;
const ll mod2= 998244353;
const ll mod3= 2147483647;
const ll mod4= 200003;
const ll INF= 5000000000000000000;
const ll INM= -5000000000000000000;
const double pi= 3.1415926535897932384626433832795;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,
rb_tree_tag,tree_order_statistics_node_update>pbds;
ll lcm(ll a, ll b) 
{ return (a*b)/(__gcd(a,b));}
ll msb(ll a){ ll k=log(a); return 1<<k;}
ll lsb(ll a){ return (a&(-a));}
//bitset<32> x(arr[i]);
// lp(i,-1,2)lp(j,-1,2){
//   if(i*i+j*j==1||i*i+j*j==2){
//     perform add of i and j in for new index
//   }
// }
//my_multiset.erase(my_multiset.equal_range(key).first);
//s.erase(s.find_by_order(s.order_of_key(k)));
// agar lambda function tle de to normal function se check karo
// kabhi bhi customized comparator mai ambiguous condition n dalo
// memory ke wajah se tle ate hai,,isliye efficient hi likho
// submit karne se pehle dekh le...it cost less than penalty
// kabhi  if else ek sath n likhe ,curly braces likhe
// kbhi bhi (i>>j) ko prefer kare (i<<j) iski jagah
// ordered set mai gretaer,less ye sab ek bar dekh le
// debug ke liye comment karke check kare
void solve()
{
   ll n;cin>>n;
   ll a[n];
   lp(i,0,n)cin>>a[i];
}
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  lp(i,1,t+1)
  { //cout<<"Case #"<<i<<": ";
  solve();}
}