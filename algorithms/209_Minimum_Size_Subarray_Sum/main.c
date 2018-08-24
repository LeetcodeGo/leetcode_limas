/*
* Source : https://leetcode.com/problems/minimum-size-subarray-sum/description/
* 
* Author : Jackal Lin
* 
* Description:
*   Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
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

int minSubArrayLen(int s, int* nums, int numsSize)
{
    int *head=nums;
    int *tail=nums;
    int cnt=numsSize+1;
    int sum=0;

    while((tail<(nums+numsSize)) || (sum >= s))
    {
        if(sum<s)
        {
            sum += *(tail++);
        }
        else
        {
            if(cnt > (tail-head))
                cnt = (int)(tail-head);

            sum -= *(head++);
        }
    }

    return (cnt==numsSize+1)?(0):(cnt);
}

