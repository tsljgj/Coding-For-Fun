#include<bits/stdc++.h>
using namespace std;

int a[15],f[15];

int main(void)
{
    a[1] = 1;
    for(int i = 2;i <= 12;++i)
        a[i] = 1 + a[i-1] * 2;

    memset(f,0x3f,sizeof(f));
    f[0] = 0;

    for(int i = 1;i <= 12;++i)
    {
        for(int j = 0;j < i;++j)
            f[i] = min(f[i],f[j] * 2 + a[i - j]);
    }

    for(int i = 1;i <= 12;++i)
        cout << f[i] << endl;

    return 0;
}


