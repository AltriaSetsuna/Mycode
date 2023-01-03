#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    string s;
    char c;
    cin >> n >> c >> s;
    s += s;
    n <<= 1;
    if(c=='g')
    {
        cout << '0' << endl;
    }
    else 
    {
        LL ans = 0;
        for (LL i = 0; i < n;i++)
        {
            if(s[i]==c)
            {
                LL t = 0;
                while(s[i]!='g'&&i<n)
                {
                    t++;
                    i++;
                }
                ans = max(ans, t);
            }   
        }
        cout << ans << endl;
    }
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