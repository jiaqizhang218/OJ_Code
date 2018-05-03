#include<bits/stdc++.h>
#define ll long long
#define mp(x,y) make_pair(x,y) 
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int a[100010];
map<pair<int,int>,bool>p; 
int main()
{
	int n,maxh,m,s;
	n = read(),s = read(),maxh = read(),m=read();
	for(int i = 1 ; i <= m ; i++)
	{
		int x= read(), y = read();
		if(x > y) swap(x,y);
		if(p[mp(x,y)]) continue;
		p[mp(x,y)] = true;	//∑¿÷π«¯º‰÷ÿ∏¥ 
		a[x+1]--;
		a[y]++;
	}
	int ans=0;  
    for(int i=1;i<=n;i++)  
    ans+=a[i],printf("%d\n",maxh+ans);  
}

