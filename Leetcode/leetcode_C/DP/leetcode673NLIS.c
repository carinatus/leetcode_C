/* 在leetcode300的基础上加一个储存*/
int findNumberOfLIS(int* nums, int numsSize){
    
    if(!numsSize) return 0;
    
    int dp[numsSize];
    int paths[numsSize]; // 记录当前长度的子序列数
    int max = 1;
    int ret = 0;

    for(int i = 0; i < numsSize; i++){
        
        dp[i] = 1;
        paths[i] = 1;
        
        for(int j = 0; j < i; j++){
            
            if(nums[i] > nums[j]){

                // 当下一个数仍然为增，且子序列长度加一后大于目前序列长度，那么新的最大长度的子序列数不变
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    paths[i] = paths[j];
                }
                // 只有当子序列长度加一后等于目前的最大长度，才在子序列数上加1
                else if (dp[j] + 1 == dp[i]){
                    paths[i] += paths[j];
                }
            }
        }

        if(dp[i] > max){ 
            max = dp[i];
            ret = paths[i];
        }
        else if (dp[i] == max){
            ret += paths[i];
        }
    }
    return ret;
}