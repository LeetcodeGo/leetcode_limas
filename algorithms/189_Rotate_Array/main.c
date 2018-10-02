/*
* Source : https://leetcode.com/problems/rotate-array/description/
*
* Author : Jackal Lin
*
* Description:
*   Given an array, rotate the array to the right by k steps, where k is non-negative.
*
* Note:
*   1. Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*   2. Could you do it in-place with O(1) extra space?
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

void rotate(int* nums, int numsSize, int k)
{
    int i;
    int idx=0;
    int next;
    int head=0;
    int tmp;

    k %= numsSize;
    if(0 == k)
        return;

    for(i=0, tmp=nums[0]; i<numsSize; i++)
    {
        next = (idx+k)%numsSize;
        nums[head] = nums[next];
        nums[next] = tmp;
        tmp = nums[head];

        idx += k;
        idx %= numsSize;
        if(idx == head)
        {
            head++;
            idx = head;
            tmp = nums[head];
        }
    }
}

