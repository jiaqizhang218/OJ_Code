#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 100100;
const int M = 250200;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,i,j,x,y,tot,v[N],a[N],X[M],Y[M],du[N],fir[N],la[M],ne[M];long long ans;
void ins(int x,int y){la[++tot]=y;ne[tot]=fir[x];fir[x]=tot;}
int main(){
    for(n=read(),m=read(),i=1;i<=n;i++)a[i]=read();
    for(i=1;i<=m;i++)X[i]=read(),Y[i]=read(),du[X[i]]++,du[Y[i]]++;
    for(i=1;i<=m;i++)du[X[i]]<du[Y[i]]?ins(X[i],Y[i]):ins(Y[i],X[i]);
    for(x=1;x<=n;x++){
        for(i=fir[x];i;i=ne[i])v[la[i]]=x;
        for(i=fir[x];i;i=ne[i])for(j=fir[y=la[i]];j;j=ne[j])if(v[la[j]]==x)ans+=max(max(a[x],a[y]),a[la[j]]);
    }
    printf("%lld",ans);
}
