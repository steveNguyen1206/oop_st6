#ifndef _INETGER_H
#define _INETGER_H

class Integer
{
public:
    static int FindGcd(int a, int b)
    {
        if(b == 0)
            return a;
        return FindGcd(b, a % b);
    }
};

#endif