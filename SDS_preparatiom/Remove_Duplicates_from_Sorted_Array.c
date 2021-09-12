
int removeDuplicates(int* nums, int numsSize){
    
    if(numsSize == 0){
        return 0;
    }
    
    int i=1;
    int key = 1;
    while(i<numsSize){
        if(nums[i] != nums[i-1]){
            nums[key] = nums[i];
            key++;
        }
        i++;
    }
    return key;
}