// shortest Common Supersequence(LCS)
#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        
        int dp[m+1][n+1];
        for(int i = 0; i< m+1; i++){
            for(int j = 0; j< n+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i< m+1; i++){
            for(int j = 1; j< n+1; j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int ans = (m + n) - (dp[m][n]);
        return ans;
    }
int main(){
    int n, m;
    cin >> n >> m;
    string x;
    string y;
    cin >> x;
    cin >> y;

    cout<<shortestCommonSupersequence(x, y, n, m)<<'\n';

}