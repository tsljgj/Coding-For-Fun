#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define fic(i,a,b) for(int i=a;i>=b;i--)
#define Mod 131 //P进制
const int N=1000007;
char s[N];
ull f1[N],f2[N],p[N];
int ans,t,l,r,mid;
ull Hash1(int i,int j)//正字符串的哈希值
{
    return (f1[j]-f1[i-1]*p[j-i+1]);
}
ull Hash2(int i,int j)//反字符串的哈希值
{
    return (f2[i]-f2[j+1]*p[j-i+1]);
}
void init()
{
    p[0]=1;//p^0为1
    fir(i,1,N-1)
        p[i]=p[i-1]*131;//P进制的位值
}
int main()
{
    init();
    while (++t)
    {
        ans=0;
        scanf("%s",s+1);
        int len=strlen(s+1);
        if (strcmp(s+1,"END")==0) //结束读入
            return 0;
        f2[len+1]=0;//初始化要注意,不然的话容易GG
        fir(i,1,len) 
            f1[i]=f1[i-1]*Mod+(s[i]-'a'+1);//前缀和
        fic(i,len,1)
            f2[i]=f2[i+1]*Mod+(s[i]-'a'+1);//后缀和
        fir(i,1,len)
        {
            l=0,r=min(i-1,len-i);//二分枚举长度为奇数的字符串 记住这里l一定要为0,不然的话,你会发现最后一个数据会卡死你.
            while(l<r)
            {
                mid=l+r+1>>1;
                if (Hash1(i-mid,i-1)==Hash2(i+1,i+mid))//如果这是一个回文串的话
                    l=mid;
                else
                    r=mid-1;
            }
            ans=max(l<<1 | 1,ans);//算出最大长度
            l=0,r=min(i-1,len-i+1);//偶数字符串
            while (l<r)
            {
                mid=l+r+1>>1;
                if (Hash1(i-mid,i-1)==Hash2(i,i+mid-1))//check判断
                    l=mid;
                else
                    r=mid-1;
            }
            ans=max(l<<1,ans);//偶数字符串只需要*2
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

