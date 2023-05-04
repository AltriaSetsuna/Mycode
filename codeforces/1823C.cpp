#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;


vector<LL> least_prime_factor;
vector<LL> primes;
void LPF(LL n)
{
   least_prime_factor = vector<LL>(n + 1, 0);
   vector<bool> is_prime(n + 1, true);
   for (LL i = 2; i <= n;i++)
   {
       if(is_prime[i])
       {
           primes.emplace_back(i);
           least_prime_factor[i]=i;
       }
       for (int j = 0; j < primes.size(); j++)
       {
           LL now=i*primes[j];
           if(now>n)
           {
               break;
           }
           is_prime[now] = false;
           least_prime_factor[now] = primes[j];
           if(i%primes[j]==0)
           {
                break;
           }
       }
   }
}

inline void solve()
{
   unordered_set<LL> s;
   LL n;
   cin >> n;
   LL ans = 0;
   for (LL i = 0; i < n;i++)
   {
       LL t;
       cin >> t;
       while(t!=1)
       {
        if(s.count(least_prime_factor[t]))
        {
                s.erase(least_prime_factor[t]);
                ans++;
        }
        else
        {
            s.emplace(least_prime_factor[t]);
        }
           t /= least_prime_factor[t];
       }
   }
   cout << ans + s.size() / 3 << endl;
   return;
}


int main()
{
   LOCAL();
   LPF(1e7);
   LL t;
   cin >> t;
   while(t--)
   {
       solve();
   }
   return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
