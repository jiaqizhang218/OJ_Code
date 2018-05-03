#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=210;
int n,m,a[N];
struct node{
    int val,num;
}sa[N];
int sum[N];
bool cmp(node x,node y){return x.val>y.val;}
int num[N],val[N];
int main()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) return 0;
        sum[0]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=m;i++) scanf("%d%d",&sa[i].num,&sa[i].val);
        sort(sa+1,sa+1+m,cmp);//从大到小可以保证在数目最多的情况下值最大 
        int yu=n+1,k1=0,k2=0;//到哪 
        for(int i=1;i<=m;i++)
        {
            int l=0,r=n+1,now,mid;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(a[mid]>sa[i].val) r=mid-1;
                else l=mid+1,now=mid;
            }//找到第一个比它小的数
            num[i]=min(min(now,sa[i].num),yu-1);
            val[i]=sum[min(now,yu-1)]-sum[min(now,yu-1)-num[i]];
            yu=min(now,yu-1)-num[i]+1;
            k1+=num[i];
            k2+=val[i];
        }
        printf("%d %d\n",k1,k2); 
    }

}
