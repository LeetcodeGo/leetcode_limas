int pivotIndex(int* nums, int numsSize)
{
    int left=0;
    int right=0;
    int *ptr;
    int *tail;
    bool found=false;

    if(numsSize == 0)
        return -1;
    else if(numsSize == 1)
        return 0;

    tail = &nums[numsSize-1];

    for(ptr=tail; ptr>nums; ptr--)
        right+=(*ptr);

    ptr = nums;
    do
    {
        if(left == right)
        {
            found = true;
            break;
        }

        left += ptr[0];
        right -= ptr[1];

        ptr++;
    }while(ptr<=tail);

    if(found)
        return (int)(ptr-nums);
    else
        return -1;
}
