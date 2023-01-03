#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define YESNO(x) puts(x?"YES":"NO")
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    unordered_map<LL, char> m;
    vector<LL> a(n);
    string s;
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    cin >> s;
    for (LL i = 0; i < n;i++)
    {
        if(m.count(a[i]))
        {
            if(m[a[i]]!=s[i])
            {
                puts("NO");
                return;
            }
            
        }
    else 
        {
            m[a[i]] = s[i];
        }
    }
    puts("YES");
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