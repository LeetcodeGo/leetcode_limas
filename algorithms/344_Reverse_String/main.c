/*
* Source : https://leetcode.com/problems/reverse-string/description/
*
* Author : Jackal Lin
*
* Description:
*   Write a function that takes a string as input and returns the string reversed.
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

char* reverseString(char* s)
{
    char *head;
    char *tail;

    if((s[0] == 0) || (s[1] == 0))
        return s;

    head = s;
    tail = s+1;
    while(tail[1] != 0)
        tail++;

    while(head < tail)
    {
        *head ^= *tail;
        *tail ^= *head;
        *head ^= *tail;

        head++;
        tail--;
    }

    return s;
}

