nt dominantIndex(int* nums, int numsSize)
{
    int i;
    int idx=0;
    int largest=nums[0];
    int sec_largest=0;

    for(i=1; i<numsSize; i++)
    {
        if(nums[i]>largest)
        {
            sec_largest = largest;
            largest = nums[i];
            idx = i;
            continue;
        }

        if(nums[i]>sec_largest)
        {
            sec_largest = nums[i];
        }
    }

    return (largest >= (sec_largest<<1))?(idx):(-1);
}
