#define MAXSIZE  20001
int longestArithSeqLength(int* A, int ASize){

    int dp[ASize][MAXSIZE];
    int res = 1;
    int diff;
    
    for(int i = 0; i < ASize; i++){
        for(int j = 0; j < MAXSIZE; j++){
            dp[i][j] = 1;
        }
    }

    for(int i = 0; i < ASize; i++){
        for(int j = 0; j < i; j++){
            
            diff = A[i] - A[j];
            diff += 10000; // 防止出现负数
            dp[i][diff] = fmax(dp[i][diff], dp[j][diff] + 1);
            res = fmax(res, dp[i][diff]);
        }
    }

    return res;
}