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

LL ans = 0;
vector<LL> a, temp;
void msort(LL l,LL r)
{
    if(l>=r)
        return;
    LL mid = l + r >> 1LL;
    msort(l, mid);
    msort(mid + 1, r);
    LL left = l, pos = l;
    for (LL right = mid + 1; right <= r; right++)
    {
        while(left<=mid&&a[left]>a[right])
        {
            temp[pos++]=a[left];
            left++;
        }
        temp[pos++] = a[right];
        ans += left - l;
    }
    while(left<=mid)
    {
        temp[pos++] = a[left++];
    }
    for (LL i = l; i <= r;i++)
    {
        a[i] = temp[i];
    }
    return;
}
inline void solve()
{
      LL n;
      cin >> n;
      a = vector<LL>(n);
      temp = vector<LL>(n);
      for (LL i = 0; i < n;i++)
      {
         cin >> a[i];
      }
      msort(0, n-1);
      cout << ans;

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
