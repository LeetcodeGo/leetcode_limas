/*
* Source : https://leetcode.com/problems/implement-strstr/description/
*
* Author : Jackal Lin
*
* Description:
*   Implement strStr().
*   Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
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

int strStr(char* haystack, char* needle)
{
    size_t len_src;
    size_t len_trg;
    int i;
    char *start = haystack;
    char *end;
    char *next;

    len_src = strlen(haystack);
    len_trg = strlen(needle);

    if(len_trg > len_src)
        return -1;

    if(len_trg == 0)
        return 0;

    end = start+(len_src-len_trg+1);

    while(start<end)
    {
        next = start+1;
        if(start[0] == needle[0])
        {
            next = NULL;
            for(i=1; i<len_trg; i++)
            {
                if((next == NULL) && (start[i] == needle[0]))
                    next = &start[i];

                if(start[i] != needle[i])
                    break;
            }

            if(i == len_trg)
                return start-haystack;

            if(next == NULL)
                next = &start[i+1];
        }

        start = next;
    }

    return -1;
}

int strStr2(char* haystack, char* needle)
{
    size_t len_src;
    size_t len_trg;
    int i;
    char *start = haystack;
    char *end;
    char *next;

    len_src = strlen(haystack);
    len_trg = strlen(needle);

    if(len_trg > len_src)
        return -1;

    if(len_trg == 0)
        return 0;

    end = start+(len_src-len_trg+1);

    while(start<end)
    {
        next = NULL;
        for(i=0; i<len_trg; i++)
        {
            if((next == NULL) && (start[i] == needle[0]) && (i != 0))
                next = &start[i];

            if(start[i] != needle[i])
                goto _not_match;
        }

        return start-haystack;

_not_match:
        if(next == NULL)
            next = &start[i+1];

        start = next;
    }

    return -1;
}

