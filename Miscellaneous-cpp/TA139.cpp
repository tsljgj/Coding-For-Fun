#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define fic(i,a,b) for(int i=a;i>=b;i--)
#define Mod 131 //P����
const int N=1000007;
char s[N];
ull f1[N],f2[N],p[N];
int ans,t,l,r,mid;
ull Hash1(int i,int j)//���ַ����Ĺ�ϣֵ
{
    return (f1[j]-f1[i-1]*p[j-i+1]);
}
ull Hash2(int i,int j)//���ַ����Ĺ�ϣֵ
{
    return (f2[i]-f2[j+1]*p[j-i+1]);
}
void init()
{
    p[0]=1;//p^0Ϊ1
    fir(i,1,N-1)
        p[i]=p[i-1]*131;//P���Ƶ�λֵ
}
int main()
{
    init();
    while (++t)
    {
        ans=0;
        scanf("%s",s+1);
        int len=strlen(s+1);
        if (strcmp(s+1,"END")==0) //��������
            return 0;
        f2[len+1]=0;//��ʼ��Ҫע��,��Ȼ�Ļ�����GG
        fir(i,1,len) 
            f1[i]=f1[i-1]*Mod+(s[i]-'a'+1);//ǰ׺��
        fic(i,len,1)
            f2[i]=f2[i+1]*Mod+(s[i]-'a'+1);//��׺��
        fir(i,1,len)
        {
            l=0,r=min(i-1,len-i);//����ö�ٳ���Ϊ�������ַ��� ��ס����lһ��ҪΪ0,��Ȼ�Ļ�,��ᷢ�����һ�����ݻῨ����.
            while(l<r)
            {
                mid=l+r+1>>1;
                if (Hash1(i-mid,i-1)==Hash2(i+1,i+mid))//�������һ�����Ĵ��Ļ�
                    l=mid;
                else
                    r=mid-1;
            }
            ans=max(l<<1 | 1,ans);//�����󳤶�
            l=0,r=min(i-1,len-i+1);//ż���ַ���
            while (l<r)
            {
                mid=l+r+1>>1;
                if (Hash1(i-mid,i-1)==Hash2(i,i+mid-1))//check�ж�
                    l=mid;
                else
                    r=mid-1;
            }
            ans=max(l<<1,ans);//ż���ַ���ֻ��Ҫ*2
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

