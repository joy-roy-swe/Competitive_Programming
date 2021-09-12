

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2; 
    int* result = (int*) calloc(2, sizeof(int));
    for(int i=0; i<numsSize; i++){
        recursion(0, nums, numsSize, result, target-nums[i], i);
    }
    return result;
}

void recursion(int j, int* nums, int numsSize, int* result, int target, int i){
    if(j==numsSize){
        return;
    }
    if(nums[j] == target && (j != i)){
        result[0] = i;
        result[1] = j;
        return;
    }
    else{
        recursion(j+1, nums, numsSize, result, target, i);
    }

}