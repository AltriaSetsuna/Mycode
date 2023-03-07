#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

const LL mod = 19260817;
template<typename T>
LL exgcd(LL a, LL b, T &x, T &y)  // 扩展欧几里得算法, 求x, y,使得ax + by = gcd(a, b)
{
    if (b==0LL)
    {
        x = 1; y = 0;
        return a;
    }
    LL res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}
void read(long long &x, long long mod)
{
    long long f=1;x=0;char s=getchar();
    while(s>'9'||s<'0')
    {
        if(s=='-')
        {
            f=-f;
        }
        s=getchar();
    }
    while(s<='9'&&s>='0')
    {
        x = (x * 10LL + (long long)(s - '0')) % mod;
        s=getchar();
    }
    x=x*f;
}

LL qpow(LL x,LL n,LL mod)//x^n%mod
{
   LL ans = 1;
   while(n)
   {
       if(n&1)
       {
           ans = ans * x % mod;
       }
       x = x * x % mod;
       n /= 2;
   }
   return ans;
}

int main()
{
   LOCAL();

   LL a, b;
   read(a, mod), read(b, mod);
   if(b==0)
   {
       cout << "Angry";
   }
   else
   {
       LL x, y;
       exgcd(b, mod, x, y);
       x = (x + mod) % mod;
       cout << a * x % mod;
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
