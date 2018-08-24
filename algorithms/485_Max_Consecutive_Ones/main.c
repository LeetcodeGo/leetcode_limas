/*
* Source : https://leetcode.com/problems/max-consecutive-ones/description/
*
* Author : Jackal Lin
*
* Description:
*   Given a binary array, find the maximum number of consecutive 1s in this array.
*
* Note:
*   The input array will only contain 0 and 1.
*   The length of input array is a positive integer and will not exceed 10,000
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

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int *ptr=nums;
    int cnt=0;
    int ret=0;

    while(ptr<(nums+numsSize))
    {
        if(0 == *ptr)
        {
            if(cnt > ret)
                ret = cnt;

            cnt = 0;
        }
        else
        {
            cnt++;
        }

        ptr++;
    }

    if(cnt > ret)
        return cnt;
    else
        return ret;
}

