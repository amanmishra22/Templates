vll lcp(string& s){
  ll n=s.size();
  vll p(n);
  lp(i,1,n){
    ll j=p[i-1];
    while(j>0&&s[i]!=s[j])j=p[j-1];
    if(s[i]==s[j])j++;
    p[i]=j;
  }
  return p;
}
vll kmp_match(string& pat,string& text){
  string tmp=pat+"#"+text;
  vll v=lcp(tmp),occurrences;
  lp(i,0,v.size())if(v[i]==pat.size())occurrences.eb(i-2*pat.size());
  return occurrences;
}