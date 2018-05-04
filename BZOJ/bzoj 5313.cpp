#include<bits/stdc++.h>
using namespace std;
const int fib[]={0,1,1,2,3,0,3,3,1,4,0,4,4,3,2,0,2,2,4,1};
int qi,q;
int main() {
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&qi);
        printf("%d\n",fib[qi%20]);
    }
    return 0;
}
