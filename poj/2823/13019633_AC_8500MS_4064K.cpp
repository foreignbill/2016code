#include<cstdio>
char c;
int i,n,k,f[1000050],L,R,H,x,D[1000050];
inline int getmin(){
    while (D[L]<=i-k) L++;
    return f[D[L]];
};  
inline void insertmin(){
    while (L<=R&&f[D[R]]>=f[i]) R--;
    D[++R]=i;
};  
inline int getmax(){
    while (D[L]<=i-k) L++;
    return f[D[L]];
};  
inline void insertmax(){
    while (L<=R&&f[D[R]]<=f[i]) R--;
    D[++R]=i;
};  
inline void put(int x){
    if(x< 0){
        putchar('-');
        x = -x;
    }
    if(x == 0){
        putchar('0');
        return;
    }
    char s[20];
    int bas = 0;
    for(;x;x/=10)s[bas++] = x%10+'0';
    for(;bas--;)putchar(s[bas]);
    return;
}
int main(){
    while (true){
        c=getchar();
        if (c==' ') break;
        n=n*10+c-48;    
    }
    while (true){
        c=getchar();
        if (c=='\n') break;
        k=k*10+c-48;    
    }
    int y=1;
    while (true){
        c=getchar();
        if (c=='\n') {f[++H]=x*y;break;}
        if (c==' ') {f[++H]=x*y;y=1;x=0;};
        if (c=='-') y=-1;
        if (c>='0'&&c<='9') x=x*10+c-48;
    }   
    L=0;R=-1;
    for (i=1;i<=n;i++){
        insertmin();
        if (i>=k) {
            put(getmin());
            if (i<n) putchar(' ');
            }
        }   
    putchar('\n');
    L=0;R=-1;
    for (i=1;i<=n;i++){
        insertmax();
        if (i>=k) {
            put(getmax());
            if (i<n) putchar(' ');
            }
        }
    putchar('\n');
    return 0;
}