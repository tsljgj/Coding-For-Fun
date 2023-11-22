//Dijkstra + A*
#include<bits/stdc++.h>

const int maxx=1001;
struct Node{
    int y,to,next;
}e[maxn],e1[maxn];
int head[maxx],tot,head1[maxx],cnt;//head1Ϊ����� 
int n,m,dis[maxx],S,T,K,vis[maxx];
inline void add(int x,int y,int z){
    e[++tot]=(Node){y,z,head[x]};
    head[x]=tot;
}
inline void add1(int x,int y,int z){//���� 
    e1[++cnt]=(Node){y,z,head1[x]};
    head1[x]=cnt;
}
priority_queue<pair<int,int> >q;//ע�⣺���Ǵ���� 
inline void dijkstra(){
    mem(dis,0x3f); mem(vis,-1);
    dis[T]=0;
    q.push(make_pair(0,T));
    while(q.size()){
        int x=q.top().second;q.pop();
        if(!vis[x])continue; vis[x]=0;//ÿ����ֻ����һ��
        for(int i=head1[x];i;i=e1[i].next){
            int y=e1[i].y;
            if(dis[y]>dis[x]+e1[i].to){
                dis[y]=dis[x]+e1[i].to;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
inline void A_star(){
    if(dis[S]==dis[0]){puts("-1");return;}//����ͨ 
    if(S==T) K++;//·�������б߰ɡ� 
    mem(vis,0);
    q.push(make_pair(-dis[S],S));
    while(q.size()){
        int x=q.top().second,d=-q.top().first-dis[x];
        q.pop(); vis[x]++;
        if(vis[T]==K){printf("%d",d);return;}
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].y;
            if(vis[y]!=K)q.push(make_pair(-d-e[i].to-dis[y],y));
//��Ҫ��֦������ΪĬ��Ϊ����Ѳ���ÿ��ȡ��Сֵ�����Ա�������෴��������������� 
        }
    }
    puts("-1"); 
}
signed main(){
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z); add1(y,x,z);
    }
    S=read(); T=read(); K=read();
    dijkstra();//�ܷ�ͼ���������Ĺ��ۺ���
    A_star(); 
    return 0;
}  


