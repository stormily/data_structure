#include<cstdio>  
#include<cstring>  
#define max(a, b) (a > b ? a : b)  
char s1[1010],s2[1010];  
int dp[1010][1010];  

int main()  
{  
    int len1, len2, i, j;  
    while(scanf("%s%s",s1,s2) != EOF)  
    {  
        memset(dp, 0, sizeof(dp));  
        len1=strlen(s1);  
        len2=strlen(s2);  
        for(i = 1;i <= len1; i++)  
            for(j = 1; j <= len2; j++) {  
                if(s1[i - 1] == s2[j - 1])  
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                else  
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            }  
        printf("%d\n",dp[len1][len2]);  
    }  
    return 0;  
}  