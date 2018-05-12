#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 110
using namespace std;

int dp[MAX][MAX];

int main(void){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++)
                cin >> dp[i][j];
        }
        for(int i = n - 1; i >= 1; i--){//从倒数第二层开始进行运算 
            for(int j = 1; j <= i; j++){
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];//相邻两个最大的加上当前位置的值 
            }
        }
        cout << dp[1][1] << endl;
    } 
    return 0;
}