vll z_fun(string& s){
  ll n=s.size(),l=0,r=0;
  vll z(n);
  lp(i,1,n){
    if(i<r)z[i]=min(r-i,z[i-l]);
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
    if(i+z[i]>r)l=i,r=i+z[i];
  }
  return z;
}
vll z_algo_match(string& pat,string& text){
  string tmp=pat+"#"+text;
  vll v=z_fun(tmp),occurrences;
  lp(i,0,text.size())if(v[i+pat.size()+1]==pat.size())occurrences.eb(i);
  return occurrences;
}