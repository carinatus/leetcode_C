int lenLongestFibSubseq(int* arr, int arrSize){

    int dp[arrSize][arrSize];
    int max = 0;
    int sum = 0;


    for(int i = 0; i < arrSize; i++){
        
        for(int j = i+1; j < arrSize; j++){

            dp[i][j] = 2;
        }
    }

    for(int i = 0; i < arrSize; i++){
        for(int l = 0, r = i - 1; l < r;){
            
            sum = arr[l] + arr[r];
            if(sum == arr[i]){
                dp[r][i] = fmax(dp[r][i], dp[l][r] + 1);
                max = fmax(max, dp[r][i]);
                l++;
                r--;
            }
            else if (sum < arr[i]){
                l++;
            }
            else{
                r--;
            }
        }
    }
    
    return max;
}