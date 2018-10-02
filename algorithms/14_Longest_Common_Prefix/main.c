/*
* Source : https://leetcode.com/problems/longest-common-prefix/description/
* 
* Author : Jackal Lin
* 
* Description:
*   Write a function to find the longest common prefix string amongst an array of strings.
*   If there is no common prefix, return an empty string "".
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

char* longestCommonPrefix(char** strs, int strsSize)
{
    char *result;
    char *base=strs[0];
    int cnt=0;
    int i;

    while(base[cnt] != 0)
    {
        for(i=1; i<strsSize; i++)
        {
            if(strs[i][cnt] != base[cnt])
                goto _end;
        }

        cnt++;
    }
_end:
    result = (char *)malloc(cnt+1);
    memcpy((void *)result, (void *)strs[0], cnt);
    result[cnt] = 0;

    return result;
}

