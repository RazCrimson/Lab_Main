int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    static int res[2]={0,0};
    *result_count=2;
    for(int i=0;i<a_count;i++){
        if(a[i]>b[i])
            res[0]++;
        else if(a[i]<b[i])
            res[1]++;
           
    }
    return res;
    
}
