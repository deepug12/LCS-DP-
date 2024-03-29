// Minimum number of deletions and insertions.
#include<bits/stdc++.h>
using namespace std;

int minOperations(string str1, string str2, int n, int m) 
    { 
        int dp[n+1][m+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j< m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j< m+1; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int lcs = dp[n][m];
        int NoDeletions = n - lcs;
        int NoInsertions = m - lcs;
        int ans = NoDeletions + NoInsertions;
        return ans;
        
    }
int main(){
    int n, m;
    cin >> n >> m;
    string x;
    string y;
    cin >> x;
    cin >> y;

    cout<<minOperations(x, y, n, m)<<'\n';

}