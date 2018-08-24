/*
* Source : https://leetcode.com/problems/remove-element/description/
*
* Author : Jackal Lin
*
* Description:
*   Given an array nums and a value val, remove all instances of that value in-place and return the new length.
*   Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*   The order of elements can be changed. It doesn't matter what you leave beyond the new length.
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

int removeElement(int* nums, int numsSize, int val)
{
    int *end = nums+numsSize;
    int *ptr = nums;
    int *slot;

    if(numsSize == 0)
        return 0;

    /* locate the first target element */
    while((ptr<end) && (*ptr!=val))
        ptr++;

    slot=ptr;
    ptr++;
    while(ptr<end)
    {
        if(*ptr != val)
        {
            *slot = *ptr;
            slot++;
        }

        ptr++;
    }

    return (int)(slot-nums);
}

