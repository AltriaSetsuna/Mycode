#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) ((x) + (k) - 1) / (k)
#define continue(x) if(x){continue;}
#define break(x) if(x){break;}
void LOCAL();
using namespace std;

inline void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    deque<pair<LL,LL>> deq;
    for (LL i = 0; i < m;i++)
    {
        pair<LL, LL> op;
        cin >> op.first >> op.second;
        while(deq.size() && deq.back().second<=op.second)
        {
            deq.pop_back();
        }
        deq.emplace_back(op);
    }
    vector<LL> tmp = a;
    sort(tmp.begin(), tmp.begin() + deq[0].second);
    LL l = 0, r = deq[0].second - 1;

    for (LL i = 1; i < deq.size();i++)
    {
        if(deq[i-1].first==1)
        {
            for (LL j = deq[i - 1].second - 1; j >= deq[i].second;j--)
            {
                a[j] = tmp[r--];
            }
        }
        else
        {
            for (LL j = deq[i - 1].second - 1; j >= deq[i].second;j--)
            {
                a[j] = tmp[l++];
            }
        }
    }
    if(deq.back().first==1)
    {
        for (LL j = deq.back().second - 1; j >= 0;j--)
        {
            a[j] = tmp[r--];
        }
    }
    else
    {
        for (LL j = deq.back().second - 1; j >= 0;j--)
        {
            a[j] = tmp[l++];
        }
    }
    for (LL i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return;
}


int main()
{
     LOCAL();
     solve();
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
