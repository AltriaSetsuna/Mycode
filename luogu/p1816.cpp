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
template<typename T>
class ST//ST(vector<T>&a,max<T>),a从零开始记录有效数据
{
   private:
      vector<vector<T>> st;
      vector<long long> lg2;
      const T& (*fun)(const T&, const T&);

   public:
   ST(vector<T>&a,const T& (*fun)(const T&, const T&))
   {
      this->fun = fun;
      lg2 = vector<long long>(a.size() + 1);
      lg2[0] = -1;
      for (long long i = 1; i <= a.size();i++)
      {
         lg2[i] = lg2[i >> 1] + 1;
      }
      st = vector<vector<T>>(a.size() + 1, vector<T>(lg2[a.size()]+1, 0));
      for (long long i = 0; i < a.size();i++)
      {
         st[i + 1][0] = a[i];
      }
      for (long long j = 1; j <st[0].size();j++)
      {
         for (long long i = 1; i + ((long long)1 << j - 1) <= a.size(); i++)
         {
            st[i][j] = (*fun)(st[i][j - 1], st[i + ((long long)1 << j - 1)][j - 1]);
         }
      }
   }
   T query(long long l,long long r)
   {
      long long k = lg2[r - l + 1];
      return (*fun)(st[l][k], st[r - ((long long)1 << k) + 1][k]);
   }
};
inline void solve()
{
    LL n, q;
    cin >> n >> q;
    vector<LL> a(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    ST<LL> st(a, min);
    while(q--)
    {
        LL l, r;
        cin >> l >> r;
        cout << st.query(l, r) << ' ';
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
