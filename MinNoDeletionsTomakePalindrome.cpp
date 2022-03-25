//  Minimum number of deletions to make string Palindrome
#include<bits/stdc++.h>
using namespace std;

int minDeletions(string str, int n) { 
        string s = str;
        reverse(s.begin(), s.end());
        int m = s.size();
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
                if(str[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int lps = dp[n][m];
        int ans = n - lps;
        return ans;
}
int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;

    cout<<minDeletions(x, n)<<'\n';

}