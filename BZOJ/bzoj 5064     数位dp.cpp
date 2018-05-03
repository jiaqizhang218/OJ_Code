#include<bits/stdc++.h>
#define ll long long
/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
using namespace std;
const int N=100000+5;
inline ll read(){
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int cnt,tmp[20],bin[20]={1}; 
ll n,f[20][20][3];
ll dfs(int pos,int sit,int p,bool flag){
	if(!pos) return !sit&&p==2;
	if(!flag&&f[pos][sit][p]) return f[pos][sit][p];
	int mx=flag?tmp[pos]:9;
	ll ans=0;
	for(int i=0;i<=mx;i++){
		if(p==2) 
		ans+=dfs(pos-1,(sit+i*bin[pos])%13,2,i==mx&&flag);
		else if(p==1&&i==3)  
		ans+=dfs(pos-1,(sit+i*bin[pos])%13,2,i==mx&&flag);
		else 
		ans+=dfs(pos-1,(sit+i*bin[pos])%13,i==1,i==mx&&flag);
	}
	if(!flag) f[pos][sit][p]=ans;
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=18;i++) bin[i]=bin[i-1]*10%13;
	while(n){
		tmp[++cnt]=n%10;
		n/=10;
	}
	cout<<dfs(cnt,0,0,1)<<endl;
}
