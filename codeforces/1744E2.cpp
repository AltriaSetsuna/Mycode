#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

vector<LL> primes;
void get_primes(LL n)
{
   vector<bool> is_prime(n + 1, true);
   for (LL i = 2; i <= n;i++)
   {
       if(is_prime[i])
       {
           primes.emplace_back(i);
       }
       for (int j = 0; j < primes.size(); j++)
       {
           LL now=i*primes[j];
           if(now>n)
           {
               break;
           }
           is_prime[now] = false;
           if(i%primes[j]==0)
           {
                break;
           }
       }
   }
}

map<LL,LL> factor(LL x)
{
   map<LL, LL> m;
   LL pos = 0;
   while(x!=1&&pos<primes.size())
   {
    if(x%primes[pos]==0)
    {
        while(x%primes[pos]==0)
        {
            m[primes[pos]]++;
            x /= primes[pos];
        }
    }
    pos++;
   }
   if(x>1)
   {
    m[x]++;
   }
   return m;
}

inline void solve()
{
   LL a, b, c, d;
   cin >> a >> b >> c >> d;
   map<LL, LL> da = factor(a), db = factor(b);
   for(auto& x:da)
   {
    db[x.first] += x.second;
   }
   vector<LL> div1(1, 1), div2(1, 1);
   for(auto& x:db)
   {
    for (LL i = 0; i < div1.size();i++)
    {
        LL pre = div1[i];
        for (LL j = 1; j <= x.second;j++)
        {
            pre *= x.first;
            div2.emplace_back(pre);
        }
    }
    div1 = div2;
   }
   for (LL i = 0; i < div2.size();i++)
   {
    LL x = div2[i];
    LL y = a * b / x;
    x = c / x * x;
    y = d / y * y;
    if(x>a&&y>b)
    {
        cout << x << ' ' << y << endl;
        return;
    }
   }
   cout << -1 << ' ' << -1 << endl;
   return;
}


int main()
{
   LOCAL();


   LL t;
   cin >> t;
   get_primes(sqrt(1e9));
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