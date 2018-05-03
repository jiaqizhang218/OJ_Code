#include<iostream>
#include<cstdio>
using namespace std;
struct data{int ly,ry,mx,know;}tr[200001];
int n,m;
void build(int k,int l,int r)
{
     if(l==r){scanf("%d%d",&tr[k].ly,&tr[k].mx);tr[k].ry=tr[k].ly;tr[k].know=1;return;}
     int mid=(l+r)>>1;
     build(k<<1,l,mid);build(k<<1|1,mid+1,r);
     tr[k].know=(tr[k<<1].know&&tr[k<<1|1].know);
     if(tr[k<<1].ry+1!=tr[k<<1|1].ly)tr[k].know=0;
     tr[k].ly=tr[k<<1].ly;tr[k].ry=tr[k<<1|1].ry;
     tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
}	//到一个具体节点就读入  
 
int get(int k,int x)
{    
    if(tr[k].ly==tr[k].ry)
    {
        if(tr[k].ly!=x)		return 0;                
        else return tr[k].mx;
    }
    if(x<=tr[k<<1].ry)	return get(k<<1,x);
    else if(x>=tr[k<<1|1].ly)	return get(k<<1|1,x);
    return 0;
}

int ask(int k,int x,int y,int num)			//ask 就是查询 x-y 之间的 与num比较关系有没有可能的 
{
    bool f=0;
    if( x < tr[k].ly )	{ f=1 ; x = tr[k].ly; }
    if(tr[k].ly==x&&tr[k].ry==y)
    	{
            if(tr[k].mx>=num)return 0;	//这个区间还有比他更大的 
            else if(tr[k].know&&!f)return 1; //表示在这个区间且没有比他大的且这个区间的都知道 所以返回1 
            else return 2;	//否则就是不知道呗 
    	} 
    if(y<=tr[k<<1].ry)		//如果求的区间比左半边的右端点还小左的话 向左走 
    {         
         return ask(k<<1,x,y,num);
     }
    else if(x>=tr[k<<1|1].ly)		//如果求的区间比右半边的左还要右的话 向右走 
    {
         return ask(k<<1|1,x,y,num);
     }
    else //否则剩下的情况  即被分割了 
    {
         int t1=ask(k<<1,x,tr[k<<1].ry,num);
         int t2=ask(k<<1|1,tr[k<<1|1].ly,y,num);  //分别分成两半来计算 
         if(!t1||!t2)return 0;			//如果有一个返回过来不可能 则就是不可能 
         else if(tr[k<<1].ry+1!=tr[k<<1|1].ly)return 2;	//在两个都可能的情况下  但是区间没有接上 即中间有未知的空白 则maybe 
         else return 1;		//剩下的自然就是必然正确了 
     } 
}

int getnext(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;		//在节点为k的树中 查询出来的 x  
    if(l==r)return tr[k].ly;		 
    if(x<tr[k<<1].ry)return getnext(k<<1,x);
    else return getnext(k<<1|1,x);
}
//next函数是尽量往左找 即找开头    而last函数是尽量往右找 即找结尾 
int getlast(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;
    if(l==r)return tr[k].ly;
    if(x>tr[k<<1|1].ly)return getlast(k<<1|1,x);
    else return getlast(k<<1,x);
}
 
int main()
{
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
            int l,r;
            scanf("%d%d",&l,&r);
            if(r<l){printf("false\n");continue;}
            //询问第r年是不是第l年后最大的一年 且 要小于l的降水 
            int lnum=get(1,l),rnum=get(1,r);	// 这个找的是最大值？？？ 
            if(!lnum&&!rnum)printf("maybe\n");	//不知道就是maybe 
            else 
			{
			int s=getnext(1,l),t=getlast(1,r);	  
            if(!lnum)			//不知道 开头 
            {
            	if(s>t||r==t){printf("maybe\n");continue;}
           	    int f=ask(1,s,t,rnum);
            	if(f==0)printf("false\n");
				else printf("maybe\n");
            }
            else if(!rnum)
            {
            	if(s>t||l==s){printf("maybe\n");continue;}
           	    int f=ask(1,s,t,lnum);
            	if(f==0)printf("false\n");
				else printf("maybe\n");
            }
            else 
            {
            		//两个都能知道的情况 
            	if(rnum>lnum){printf("false\n");continue;} //右边比左边大 GG
				 
            	if(s>t){
				     if(l+1==r) printf("true\n");
				     else printf("maybe\n");
				     continue;
					 }
            	int f=ask(1,s,t,rnum);
            	if(f==0)printf("false\n");
            	else if(f==1)
            	{
           	        if(l+1==s&&r-1==t)printf("true\n");
           	        else printf("maybe\n");
           	    }
            	else if(ask(1,s,t,rnum)==2)printf("maybe\n");
            	else printf("false\n");
            }
        }
    }
    return 0;
}
