#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
const int maxn = 10009;
const int maxpn = 1500;
 
int N, M;
int p[maxpn], pn = 0;
int a[2][maxpn];
bool check[maxn];
 
void init() {
	scanf("%d%d", &N, &M);
	memset(check, 0, sizeof check);
	for(int i = 2, lim = N + M; i <= lim; i++) {
		if(!check[i]) p[pn++] = i;
		for(int j = 0; j < pn && i * p[j] <= lim; j++) {
			check[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
	memset(a, 0, sizeof a);
	for(int i = N + 2; i <= N + M; i++)
		for(int j = 0, t = i; j < pn && t >= p[j]; j++)
			for(; t % p[j] == 0; a[0][j]++, a[1][j]++, t /= p[j]);
	for(int t = N + 1, j = 0; j < pn && t >= p[j]; j++)
		for(; t % p[j] == 0; a[0][j]++, t /= p[j]);	
	for(int i = 2; i < M; i++)
		for(int j = 0, t = i; j < pn && t >= p[j]; j++)
			for(; t % p[j] == 0; a[0][j]--, a[1][j]--, t /= p[j]);
	for(int t = M, j = 0; j < pn && t >= p[j]; j++)
		for(; t % p[j] == 0; a[0][j]--, t /= p[j]);
}
 
struct Int {
	static const int base = 10000;
	static const int maxn = 1000;
	static const int width = 4;
	int s[maxn], n;
	
	Int() : n(0) {
		memset(s, 0, sizeof s);
	}
	
	Int operator = (int num) {
		n = 0;
		for(; num; num /= base) s[n++] = num % base;
		return *this;
	}
	
	Int(int x) {
		*this = x;
	}
	
	Int operator = (const Int &o) {
		n = o.n;
		memcpy(s, o.s, sizeof(int) * n);
		return *this;
	}
	
	void write() {
		int buf[width];
		for(int i = n; i--; ) {
			int t = s[i], c = 0;
			for(; t; t /= 10) buf[c++] = t % 10;
			if(i + 1 != n)
				for(int j = width - c; j; j--) putchar('0');
			while(c--) putchar(buf[c] + '0');
		}
		puts("");
	}
	
	Int operator + (const Int &o) const {
		Int res;
		for(int i = 0, g = 0; ; i++) {
			if(!g && i >= o.n && i >= n) break;
			int x = g + (i < n ? s[n] : 0) + (i < o.n ? o.s[o.n] : 0);
			res.s[res.n++] += x / base;
			g = x % base;
		}
		return res;
	}
	
	Int operator += (const Int &o) {
		return (*this = *this + o);
	}
	
	Int operator * (const Int &o) const {
		Int ret; ret.n = o.n + n - 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < o.n; j++) {
				int t = s[i] * o.s[j];
				ret.s[i + j] += t % base;
				ret.s[i + j + 1] += t / base;
			}
		for(int i = 0; i < ret.n; i++) if(ret.s[i] >= base) {
			ret.s[i + 1] += ret.s[i] / base;
			ret.s[i] %= base;
		}
		for(int &i = ret.n; ret.s[i]; i++) {
			ret.s[i + 1] += ret.s[i] / base;
			ret.s[i] %= base;
		}
		return ret;
	}
	
	Int operator *= (const Int &o) {
		return (*this = *this * o);
	}
	
	Int operator - (const Int &o) const {
		Int ret = *this;
		for(int i = ret.n; --i; ) {
			ret.s[i]--; ret.s[i - 1] += base;
		}
		for(int i = 0; i < o.n; i++)
			if((ret.s[i] -= o.s[i]) >= base)
				ret.s[i + 1]++, ret.s[i] -= base;
		if(!ret.s[n - 1]) ret.n--;
		return ret;
	}
	
};
 
Int power(int p, int a) {
	Int ret = 1, _p = p;
	for(; a; _p *= _p, a >>= 1) if(a & 1) ret *= _p;
	return ret;
}
 
int main() {
	
	init();
	Int ans = 1, t = 1;
	for(int i = 0; i < pn; i++)
		ans *= power(p[i], a[0][i]), t *= power(p[i], a[1][i]);
	(ans - t).write();
	
	return 0;
}
