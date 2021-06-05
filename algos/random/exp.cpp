//log N exponent with mod

long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}