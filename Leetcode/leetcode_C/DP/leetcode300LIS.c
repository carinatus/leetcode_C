/* 采用动态规划 —— 两种解法 */
/* 
* 思路
* 总结： 解决动态规划问题最难的地方有两点：
*     1.如何定义 f(n)f(n)
*     2.如何通过 f(1)f(1), f(2)f(2), … f(n - 1)f(n−1) 推导出 f(n)f(n)，即状态转移方程
*/

/* 法一：递归 */

int lengthOfLIS(int * nums, int numsSize){

    int i = numsSize - 1;
    int a = 1;

    for (int j = 0; j < i; ++j)
    {
        a = (a > lengthOfLIS(nums, j) + 1)?a:lengthOfLIS(nums, j) + 1;

    }

    return a;  
}


/* 法二：迭代 */
int lengthOfLIS(int* nums, int numsSize){

    int dp[numsSize];
    int a = 1;
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
    }

    for(int i = 0; i < numsSize; i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                dp[i] = (dp[i]>(dp[j]+1))?dp[i]:(dp[j]+1);
                
            }
        }
        a = a>dp[i]?a:dp[i];
    }
    return a;
}
