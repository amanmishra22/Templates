vll rabin_karp_match(string& pat,string& text){
  ll p=31,pats=pat.size(),txts=text.size(),hash_val_pat=0;
  vll p_pow(max(pats,txts)),h(txts+1,0);
  p_pow[0]=1;
  lp(i,1,p_pow.size())p_pow[i]=(p_pow[i-1]*p)%mod1;
  lp(i,0,txts)h[i+1]=(h[i]+(text[i]-'a'+1)*p_pow[i])%mod1;
  lp(i,0,pats)hash_val_pat=(hash_val_pat+(pat[i]-'a'+1)*p_pow[i])%mod1;
  vll occurrences;
  lp(i,0,txts-pats+1){
    ll curhash=(h[i+pats]+mod1-h[i])%mod1;
    if(curhash==hash_val_pat*p_pow[i]%mod1)occurrences.eb(i);
  }
  return occurrences;
}