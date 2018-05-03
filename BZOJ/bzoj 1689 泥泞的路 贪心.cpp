#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,l,now,ans;
struct data{int x,y;}a[10001];
bool cmp(data a,data b)
{return a.x<b.x;}
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	   scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
    	if(now>=a[i].y)continue;
    	now=max(now,a[i].x);
    	while(now<a[i].y){ans++;now+=l;}
    }
    printf("%d",ans);
	return 0;
}
