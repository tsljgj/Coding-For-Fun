struct Big{
    int a[120], n;
    int& operator [](int x) {return a[x];}
    Big():n(1) {memset(a, 0, sizeof(a));}
    void ini(int x) {a[1]=x; n=1;}
};

Big operator *(Big a, int b) {
    int g=0;
    for(int i=1; i<=a.n; i++) 
        g += a[i]*b, a[i] = g%B, g/=B;
    if(g) a[++a.n] = g;
    return a;
}

Big operator *(Big a, Big b) {
    Big c;
    for(int i=1; i<=a.n; i++) {
        int g=0;
        for(int j=1; j<=b.n; j++) 
            g += c[i+j-1]+a[i]*b[j], c[i+j-1] = g%B, g/=B;
        c[i+b.n] = g;
    }
    c.n = a.n + b.n;
    while(c.n>1 && c[c.n]==0) c.n--;
    return c;
}

Big operator +(Big a, Big b) {
    int g=0, n=max(a.n, b.n);
    for(int i=1; i<=n; i++) {
        g += i<=a.n ? a[i] : 0;
        g += i<=b.n ? b[i] : 0;
        a[i] = g%B, g/=B;
    }
    a.n = n;
    if(g) a[++a.n] = g;
    return a;
}
void scan(big &a,char s[]){//annoy B ,if B==10 you can directly use the string
    int len=strlen(s+1);
    int p=a.size=len/W+(len%W!=0);
    for(int i=1;i<=p;i++){
        int r=len-(i-1)*W,l=max(len-i*W+1,1);
        for(int j=l;j<=r;j++) a.d[i]=a.d[i]*10+s[j]-'0';
    }
}
void print(big &a){//When B==1e4;If B==10 just print
    printf("%d",a.d[a.size]);
    for(int i=a.size-1;i>=1;i--){
        if(a.d[i]<10) printf("000");
        else if(a.d[i]<100) printf("00");
        else if(a.d[i]<1000) printf("0");
        printf("%d",a.d[i]);
    }
    putchar('\n');
}

//void scan(big &a,char s[]){
//    int len=strlen(s+1);
//    a.size=len; 
//    for(int i=1;i<=len;i++) a.d[len-i+1]=s[i]-'0';
//}
//void print(big &a){
//    for(int i=a.size;i>=1;i--) printf("%d",a.d[i]);
//}

Big operator -(Big a, Big b) {
    for(int i=1; i<=b.n; i++) {
        if(a[i]<b[i]) a[i]+=B, a[i+1]--;
        a[i] -= b[i];
    }
    int p=b.n+1;
    while(a[p]<0) a[p]+=B, a[++p]--;
    while(a.n>1 && a[a.n]==0) a.n--;
    return a;
}
bool operator <(big a,big b){//a<b
    if(a.size!=b.size) return a.size<b.size;
    for(int i=1;i<=a.size;i++)
        if(a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
    return false;//a==b
}
void Print(Big &a) {
    printf("%d", a[a.n]);
    for(int i=a.n-1; i>=1; i--) printf("%04d", a[i]);
}
