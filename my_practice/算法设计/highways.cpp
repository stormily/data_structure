#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
const int INF = 0x3f3f3f3f;  
int a[505][505];  
int dis[505];  
bool vis[505];  
int n;  
int Prime()  
{  
    for(int i = 0; i < n; i++) {  
        vis[i] = false;  
        dis[i] = a[0][i];  
    }  
    vis[0] = true;  
    dis[0] = 0;  
    int ans = 0;  
    for(int i = 1; i < n; i++) {  
        int p = -1;  
        int minn = INF;  
        for(int j = 0; j < n; j++)  
        {  
            if(!vis[j] && dis[j] < minn)  
                minn = dis[p=j];  
        }  
        vis[p] = true;  
        if(minn > ans)  
            ans=minn;  
        for(int j = 0; j < n; j++) {  
            if(!vis[j] && dis[j] > a[p][j])  
                dis[j] = a[p][j];  
        }  
    }  
    return ans;  
}  
int main()  
{  
    int T;  
    cin >> T;  
    while(T--)  
    {  
        scanf("%d",&n);  
        for(int i=0;i<n;i++) {  
            for(int j = 0; j < n; j++)  
                scanf("%d", &a[i][j]);  
        }  
        printf("%d\n",Prime());  
    }  
}