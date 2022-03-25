//  Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s, int n) {
        // int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        int m = str.size();
        int dp[n+1][m+1];
        for(int i = 0; i< n+1; i++){
            for(int j = 0; j< m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< m+1; j++){
                if(s[i-1] == str[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;

    cout<<longestPalindromeSubseq(x, n)<<'\n';

}