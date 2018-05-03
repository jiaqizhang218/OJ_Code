#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 1e4 + 5;
int n,l,T;
struct Data{
	int start,end;
	bool operator < (const Data &x) const {  
        return end != x.end ? end < x.end : start < x.start;  
    } 
}a[maxn];
int read(){
	int x = 0 , f = 1 ; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') f*=-1; ch = getchar();}
	while(ch>='0'&&ch<='9'){x = x * 10 + (ch -'0') ; ch = getchar();}
	return x * f;
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
		a[i].start=read(),a[i].end=a[i].start+read();
	sort(a+1,a+n+1);
	int ans = 0;  
    for(int i = 1, now = 0; i <= n; i++)  
        if(now <= a[i].start) ans++, now = a[i].end;  
    printf("%d\n", ans);  
    return 0;	
 } 
