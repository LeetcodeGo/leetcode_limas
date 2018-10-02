/*
* Source : https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
*
* Author : Jackal Lin
*
* Description:
*   In a given integer array nums, there is always exactly one largest element.
*   Find whether the largest element in the array is at least twice as much as every other number in the array.
*   If it is, return the index of the largest element, otherwise return -1.
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

int dominantIndex(int* nums, int numsSize)
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
            sec_largest = nums[i];
    }

    return (largest >= (sec_largest<<1))?(idx):(-1);
}
