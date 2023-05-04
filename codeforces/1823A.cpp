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

vector<LL> a(101);
inline void solve()
{
    LL n, k;
    cin >> n >> k;
    LL one = -1;
    for (LL i = 1; i <= n;i++)
    {
        if(a[i]+a[n-i]==k)
        {
            one = i;
            break;
        }
    }
    if(one==-1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (LL i = 1; i <= n;i++)
        {
            cout << (i <= one ? 1 : -1) << " \n"[i == n];
        }
    }
    return;
}


int main()
{
   LOCAL();
   a[1] = 0;
   for (LL i = 2; i <= 100;i++)
   {
        a[i] = a[i - 1] + i - 1;
   }
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
