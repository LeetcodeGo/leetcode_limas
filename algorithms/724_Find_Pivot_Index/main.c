/*
* Source : https://leetcode.com/problems/pascals-triangle/description/
*
* Author : Jackal Lin
*
* Description:
*   Given an array of integers nums, write a method that returns the "pivot" index of this array.
*   We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
*   If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
*
* Complexity:
*   Time:O(N)
*   Space:O(1)
*
* Beats: 100%
*
* Approach:
*
*/

int pivotIndex(int* nums, int numsSize)
{
    int left=0;
    int right=0;
    int *ptr;
    int *tail;

    if(numsSize == 0)
        return -1;

    if(numsSize == 1)
        return 0;

    tail = &nums[numsSize-1];

    for(ptr=tail; ptr>nums; ptr--)
        right+=(*ptr);

    ptr = nums;
    do
    {
        if(left == right)
            return (int)(ptr-nums);

        left += ptr[0];
        right -= ptr[1];

        ptr++;
    }while(ptr<=tail);

    return -1;
}
