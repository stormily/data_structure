#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
int solve(int n,int m)  
{  
    if(n == 1 || m == 1 || n == 0)  
    	return 1;  
    if(n < m)  
    	return solve(n, n);  
    else  
    	return solve(n, m-1) + solve(n-m, m);  
}  
  
int main()  
{  
    int t, n, m;  
    scanf("%d", &t);  
    
    while(t--)  
    {  
        scanf("%d%d", &n,&m);  
        printf("%d\n", solve(n,m));  
    }   
  
    return 0;  
}  