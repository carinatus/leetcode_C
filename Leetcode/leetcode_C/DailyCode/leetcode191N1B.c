int haimingWeight(uint32_t n){

    int count = 0;
    for(int i = 0; i < 32; i++){
        if (n&(1u<<i))
        {
            count++;
        }
        
    }
    return count;
}