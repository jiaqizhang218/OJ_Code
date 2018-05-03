#include<iostream>
#include<cstdio>
#include<cmath> 
#include<algorithm>
using namespace std;
void put(int x)
{
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
}
int n,k,cnt,ans;
int a[10000001];
void find(int x)
{
	for(int i=1;i<=sqrt(x);i++)
	    if(x%i==0)
		{
	    	a[++cnt]=i;
			if(i!=x/i)a[++cnt]=x/i;
     	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
	    int x;scanf("%d",&x);
	    find(x);
	}
	sort(a+1,a+cnt+1);
	int tmp=1;
	for(int i=cnt;i>0;i--)
	{
		if(a[i]==a[i+1])tmp++;
		else 
		{
		    if(tmp>=k)
			{put(a[i+1]);return 0;}
			tmp=1;
		}
	}
}
