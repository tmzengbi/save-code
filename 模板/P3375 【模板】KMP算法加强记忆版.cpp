#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn],t[maxn];
int nxt[maxn];
void getNxt(char *s){
	nxt[0]=-1;
	int n=strlen(s),k;
	for(int i=1;i<=n;++i){
		k=nxt[i-1];
		while(k!=-1&&s[k]!=s[i-1]) k=nxt[k];
		nxt[i]=k+1;
	}
}
void kmp(char *s,char *t){
	int n=strlen(s),m=strlen(t),k=0;
	for(int i=0;i<m;++i){
		while(k!=-1&&s[k]!=t[i]) k=nxt[k];
		if(++k==n) {
			printf("%d\n",i+2-n);
			k=nxt[k];
		}
	}
}
int main() {
	scanf("%s%s",s,t);
	getNxt(t);
	kmp(t,s);
	int n=strlen(t);
	for(int i=1;i<=n;++i){
		printf("%d",nxt[i]);
		if(i!=n) printf(" ");
	}
}