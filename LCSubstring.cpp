// Longest common substring
// top - down technique
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int maxi = 0;
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
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(dp[i][j], maxi);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
int main(){
    int n, m;
    cin >> n >> m;
	string s;
	string p;
	cin >> s;
	cin >> p;


	cout<<longestCommonSubstr(s, p, n, m)<<'\n';

}