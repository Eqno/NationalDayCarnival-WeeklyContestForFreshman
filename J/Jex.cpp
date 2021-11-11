#include <iostream>  
#include <cstdio>  
#include <queue>  
#include <vector>  
using namespace std;  
#define int long long
const int Ni = 1e5+10;  
const int INF = 0x3f3f3f3f3f3f3f3f;  
struct node{  
    int x,d;  
    node(){}  
    node(int a,int b){x=a;d=b;}  
    bool operator < (const node & a) const  
    {  
        if(d==a.d) return x<a.x;  
        else return d > a.d;  
    }  
};  
vector<node> eg[Ni];  
int dis[Ni],n;  
void Dijkstra(int s)  
{  
    int i;
    for(i=0;i<=n;i++) dis[i]=INF;  
    dis[s]=0;  
    //用优先队列优化  
    priority_queue<node> q;  
    q.push(node(s,dis[s]));  
    while(!q.empty())  
    {  
        node x=q.top();q.pop();  
        for(i=0;i<(long long)eg[x.x].size();i++)  
        {  
            node y=eg[x.x][i];  
            if(dis[y.x]>x.d+y.d)  
            {  
                dis[y.x]=x.d+y.d;  
                q.push(node(y.x,dis[y.x]));  
            }  
        }  
    }  
}  
signed main()  
{  
    int a,b,d,m;  
    scanf("%lld%lld",&n,&m); 
    while(m --)  
    {  
        scanf("%lld%lld%lld",&a,&b,&d);  
        eg[a].push_back(node(b,d));  
        eg[b].push_back(node(a,d));  
    }  
    Dijkstra(1);  
    printf("%lld\n",dis[n]);  
    return 0;  
}