#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 1000055;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
LL a[N],del[N];
struct node{
	LL w; int pos;
	node(LL a,int b)
	{
		w=a; pos=b; 
	}
	bool operator < (const node& rhs)	const 
	{
		return w<rhs.w;
	}
};
priority_queue<node> q;
int pre[N],nxt[N]; LL val[N];
int main()
{
	int n=read(),k=read();
	LL x,tot=1;
	a[1]=read();
	for(int i=2;i<=n;i++)
	{
		x=read(); if(!x)	continue;
		if((x>=0)==(a[tot]>=0) || a[tot]==0)	a[tot]+=x;
		else a[++tot]=x;
	}
	LL sum=0;int cnt=0;
	for(int i=1;i<=tot;i++)
		if(a[i]>=0)	sum+=a[i],cnt++;
	if(cnt<=k){//printf("!");
		printf("%lld\n",sum);
   	}else{
		k=cnt-k;
       int l=1,r=tot;
    if(a[1]<0)l++;
    if(a[tot]<0)r--;
      if(tot==1&&a[1]<0){
            printf("0\n");
        }else{
            for(int i=l;i<r;++i)nxt[i]=i+1;
            for(int i=l+1;i<=r;++i)pre[i]=i-1;
            for(int i=l;i<=r;++i)val[i]=(a[i]>=0)?(-a[i]):a[i];
            for(int i=l;i<=r;++i)q.push(node(val[i],i));
            while(k--){//printf("!");
                while(del[q.top().pos])q.pop();
                node tmp=q.top();q.pop();
                int i=tmp.pos;//printf("%d\n",tmp.w);
                sum+=tmp.w;del[pre[i]]=del[nxt[i]]=true;
                if(pre[i]&&nxt[i]){
                    val[i]=val[pre[i]]+val[nxt[i]]-val[i];
                    q.push(node(val[i],i));
                    pre[i]=pre[pre[i]];nxt[i]=nxt[nxt[i]];
                    if(nxt[i])pre[nxt[i]]=i;
                    if(pre[i])nxt[pre[i]]=i;
                }else{
                            del[i]=true;pre[i]=pre[pre[i]];nxt[i]=nxt[nxt[i]];
                    if(nxt[i])pre[nxt[i]]=pre[i];
                    if(pre[i])nxt[pre[i]]=nxt[i];
                }
            }
        }
        printf("%lld\n",sum);
    }	
	return 0;
}

