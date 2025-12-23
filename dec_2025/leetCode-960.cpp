class Solution {

    bool isTrue(vector<string>& strs, int j, int i){
        for(auto st: strs){
            if(st[j]>st[i]) return false;
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();

        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isTrue(strs,j,i)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int len=INT_MIN;
        for(auto i: dp) len = max(len,i);

        return n-len;
    }
};