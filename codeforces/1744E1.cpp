#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

LL gcd(LL a, LL b)  // ŷ������㷨
{
    return b ? gcd(b, a % b) : a;
}

inline void solve()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    LL divisior = a * b;
    for (LL x = a + 1; x <= c;x++)
    {
        LL y = divisior / gcd(divisior, x);
        y = d / y * y;
        if(y>b)
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