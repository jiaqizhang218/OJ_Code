#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int D,S,N;
int ql,qr,qd,qu;
struct segx{
	int v[3005],tag[3005];
	void change(int k,int l,int r,int x,int y,int val){
		v[k]=max(v[k],val);
		if(l==x&&y==r){tag[k]=max(tag[k],val);return;}
		int mid=(l+r)>>1;
		if(x<=mid)change(k<<1,l,mid,x,min(mid,y),val);
		if(y>mid)change(k<<1|1,mid+1,r,max(x,mid+1),y,val);
		}
	int query(int k,int l,int r,int x,int y){
		if(l==x&&y==r)return v[k];
		int mid=(l+r)>>1,ans=tag[k];
		if(x<=mid)ans=max(ans,query(k<<1,l,mid,x,min(mid,y)));
		if(y>mid)ans=max(ans,query(k<<1|1,mid+1,r,max(x,mid+1),y));
		return ans;
	}
};
struct segy{
	segx v[3005],tag[3005];
	void change(int k,int l,int r,int x,int y,int val){
		v[k].change(1,1,S,qd,qu,val);
		if(l==x&&y==r){tag[k].change(1,1,S,qd,qu,val);return;}
		int mid=(l+r)>>1;
		if(x<=mid)change(k<<1,l,mid,x,min(mid,y),val);
		if(y>mid)change(k<<1|1,mid+1,r,max(x,mid+1),y,val);
		}
	int query(int k,int l,int r,int x,int y){
		if(l==x&&y==r)return v[k].query(1,1,S,qd,qu);
		int mid=(l+r)>>1,ans=tag[k].query(1,1,S,qd,qu);;
		if(x<=mid)ans=max(ans,query(k<<1,l,mid,x,min(mid,y)));
		if(y>mid)ans=max(ans,query(k<<1|1,mid+1,r,max(x,mid+1),y));
		return ans;
	}
}T;
int main()
{
	D=read();S=read();N=read();
	int d,s,w,x,y;
	for(int i=1;i<=N;i++)
	{
		d=read();s=read();w=read();x=read();y=read();
		ql=x+1;qr=x+d;qd=y+1;qu=y+s;
		int ans=T.query(1,1,D,ql,qr);
		T.change(1,1,D,ql,qr,ans+w);
	}
	qd=1;qu=S;
	printf("%d\n",T.query(1,1,D,1,D));
	return 0;
}
