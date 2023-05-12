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

LL piece_size;
unordered_map<LL, vector<LL>> sum;
vector<LL> a;
vector<LL> mode;
LL getPiecePos(LL x)
{
    return x / piece_size + 1LL;
}
LL query(LL l,LL r)
{
    LL lPiecePos = getPiecePos(l), rPiecePos = getPiecePos(r);
    
    if(lPiecePos==rPiecePos)
    {
        unordered_map<LL, LL> m;
        pair<LL, LL> ans=make_pair(0,0);
        for (LL i = l - 1; i < r; i++)
        {
            m[a[i]]++;
            if(ans.second<m[a[i]])
            {
                ans.first = a[i];
                ans.second = m[a[i]];
            }
            else if(m[a[i]]==ans.second)
            {
                ans.first = min(ans.first, a[i]);
            }
        }
    }
    else
    {
       // pair<LL,LL>ans=make_pair(mode[lPiecePos+1][r   ])
    }
}
inline void solve()
{
    LL n,q;
    cin >> n >> q;
    piece_size = sqrt(n);
    LL sumPiece = ceil_LL(n, piece_size);
    a = vector<LL>(n);
    for (LL i = 0; i < n;i++)
    {
        cin >> a[i];
        LL piecePos = getPiecePos(i);
        if(sum.count(a[i]))
        {
            sum[a[i]][piecePos]++;
            if(i%piece_size==0)
            {
                sum[a[i]][piecePos] += sum[a[i]][piecePos - 1];
            }
        }
        else
        {
            sum[a[i]] = vector<LL>(sumPiece + 1, 0);
            sum[a[i]][piecePos]++;
        }
    }
    // for (LL i = 1; i <= sumPiece;i++)
    // {
    //     pair<LL, LL> ans = make_pair(0, 0);//first为值，second为次数
    //     for (LL j = (i - 1) * piece_size; j < n;j++)
    //     {
    //         if(sum[a[j]][i]>ans.second)
    //         {
    //             ans.first = a[j];
    //             ans.second = sum[a[j]][i];
    //         }
    //         else if(sum[a[j]][i]==ans.second)
    //         {
    //             ans.first = min(a[j], ans.first);
    //         }
    //     }
    // }
    LL lastAns = 0;
    while(q--)
    {
        LL l, r;
        cin >> l >> r;
        l = (l + lastAns - 1) % n + 1;
        r = (r + lastAns - 1) % n + 1;
        if(l<r)
            swap(l, r);
        lastAns = query(l, r);
        cout << lastAns << endl;
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
