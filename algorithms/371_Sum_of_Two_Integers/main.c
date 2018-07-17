int getSum(int a, int b)
{
    int i;
    int result=0;
    int _a;
    int _b;
    unsigned int mask=1;
    char c=0;
    char s;

    for(i=0; i<(sizeof(int)<<3); i++, mask<<=1)
    {
        _a = (a&mask);
        _b = (b&mask);
        s = _a^_b^c;
        c = ((_a&_b)|(_b&c)|(_a&c))<<1;

        result |= s;
    }

    return result;
}

