#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

void print(vector<LL>& a)
{
    for (LL i = 0; i < a.size();i++)
    {
        cout << a[i] << " \n"[i + 1 == a.size()];
    }
    return;
}
inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n), num(n + 1, 0);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
        num[a[i]]++;
    }
    multiset<LL> t;
    for (LL i = 1; i <= n;i++)
    {
        for (LL j = 2 - num[i]; j > 0;j--)
        {
            t.emplace(-i);
        }
        if(num[i]>2)
        {
            yesno(0);
            return;
        }
    }
    vector<LL> ans1, ans2;
    vector<LL> num1(n + 1, 0), num2(n + 1, 0);
    for (LL i = 0; i < n;i++)
    {
        auto it = t.lower_bound(-a[i]);
        if(it==t.end())
        {
            yesno(0);
            return;
        }
        ans1.emplace_back(a[i]);
        ans2.emplace_back(-(*it));
        num1[a[i]]++, num2[-(*it)]++;
        if(num1[a[i]]==2||num2[-(*it)]==2)
        {
            swap(ans1[i], ans2[i]);
            num1[a[i]]--, num2[-(*it)]--;
            num1[ans1[i]]++, num2[ans2[i]]++;
        }
        t.erase(it);
    }
    yesno(1);
    print(ans1); 
    print(ans2);
    return;
}


int main()
{
   LOCAL();


   LL t;
   cin >> t;
   for (LL i = 1; i <= t;i++)
   {
        // if(i<=3)
        // {
        //     solve();
        // }
        // else if(i>3&&i<597)
        // {
        //     LL n;
        //     cin >> n;
        //     while(n--)
        //     {
        //         LL x;
        //         cin >> x;
        //     }
        // }
        
        // if(i==597)
        // {
        //     LL n;
        //     cin >> n;
        //     cout << n << endl;
        //     while(n--)
        //     {
        //         LL x;
        //         cin >> x;
        //         cout << x << ' ';
        //     }
        // }
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