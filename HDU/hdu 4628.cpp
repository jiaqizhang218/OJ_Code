#include<bits/stdc++.h>
using namespace std;
const int MXN = (1<<17) + 5;

int n,f[MXN],T;

char str[20];

inline bool judge(int x) {
	int tot=0; char s[20];
	for(int i=0;i<n;++i,x>>=1) {
		if(x&1) {
			s[++tot]=str[i];
		}
	}
	for(int i=1,j=tot;i<=j;++i,--j) {
			if(s[i] != s[j]) return false;
		}
	return true;
}

inline void work() {
	memset(f,0x3f,sizeof f);
	scanf("%s",str); n = strlen(str);
	for(int i=1,ed=1<<n;i<ed;++i) {
		if(judge(i)) {
			f[i] = 1;
		} else {
			for(int j=i;j;j=(j-1)&i) 
				f[i]=min(f[i],f[j]+f[i^j]);
		}
	}
	printf("%d\n",f[(1<<n)-1]);
}


int main() {
	cin>>T;
	while(T--) work();
}
