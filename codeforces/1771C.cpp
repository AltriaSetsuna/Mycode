#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        for(int j = 0; j < (int)primes.size(); j++) {
            int p = primes[j];
            if(p * 1LL * p  > x) break;
            if(x % p == 0) {
                cnt[p]++;
                if(cnt[p] >= 2) {
                    cout << "YES\n";
                    return;     
                }
                while(x % p == 0) x /= p;
            }
        } 
        cnt[x]++;
        if(x != 1 and cnt[x] >= 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    LPF(sqrt(1e9));
    LL t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
} 
