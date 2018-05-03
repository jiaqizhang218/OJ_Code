#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,seed,vmax;
int rnd(){
    int ret=seed;
    seed=(seed*7ll+13)%1000000007;
    return ret;
}
int power(int x,int y,int mod){
    int ans=1;
    for (;y;y>>=1,x=(ll)x*x%mod)
        if (y&1) ans=(ll)ans*x%mod;
    return ans;
}
typedef pair<int,int> pii;
map<pii,ll> M;
typedef const pair<const pair<int,int>,ll> maptype;
pair<ll,int> q[N];int size;
int main()
{
    scanf("%d%d%d%d",&n,&m,&seed,&vmax);
    M[pii(0,0)]=M[pii(n+1,n+1)]=0;
    for (int i=1;i<=n;i++) M[pii(i,i)]=rnd()%vmax+1;
    for (int i=1;i<=m;i++){
        int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
        if (l>r) swap(l,r);
        map<pii,ll>::iterator p=lower_bound(M.begin(),M.end(),maptype(pii(l,r),0ll));
        while ((--p)->first.second>=l);++p;
        if (op==3) x=rnd()%(r-l+1)+1;else x=rnd()%vmax+1;
        if (op==4) y=rnd()%vmax+1;
        if (op==1){
            for (;p->first.first<=r;){
                int L=p->first.first,R=p->first.second;
                if (l<=L&&R<=r) p->second+=x,++p;
                else{
                    ll v=p->second;++p;
                    M.erase(pii(L,R));
                    if (L<l) M[pii(L,l-1)]=v;
                    M[pii(max(l,L),min(r,R))]=v+x;
                    if (R>r) M[pii(r+1,R)]=v;
                }
            }
        }
        if (op==2){
            for (;p->first.first<=r;){
                int L=p->first.first,R=p->first.second;ll v=p->second;
                ++p;
                M.erase(pii(L,R));
                if (L<l) M[pii(L,l-1)]=v;
                if (R>r) M[pii(r+1,R)]=v;
            }
            M[pii(l,r)]=x;
        }
        if (op==3){
            size=0;
            for (;p->first.first<=r;){
                int L=p->first.first,R=p->first.second;ll v=p->second;
                q[++size]=make_pair(v,min(r,R)-max(l,L)+1);
                ++p;
            }
            sort(q+1,q+size+1);
            int s=0;
            for (int i=1;i<=size;i++){
                s+=q[i].second;
                if (s>=x){printf("%lld\n",q[i].first);break;}
            }
        }
        if (op==4){
            int ans=0;
            for (;p->first.first<=r;){
                int L=p->first.first,R=p->first.second;ll v=p->second;
                ans=(ans+(ll)power(v%y,x,y)*(min(r,R)-max(l,L)+1))%y;
                ++p;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
