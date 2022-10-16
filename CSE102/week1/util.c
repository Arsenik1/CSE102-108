#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w)
{
    int r = 0;
    if (t > 35 && w != 3)
        r = 1;
    else if (t <= 35 && s == 0)
        r = 1;
    return r;
}

char dt1a(double PL, double PW, double SW, double SL)
{
    if (PL < 2.45)
    {
        return '1';
    }
    else if (PW < 1.75)
    {
        if (PL < 4.95)
        {
            if (PW < 1.65)
            {
                return '2';
            }
            else
            {
                return '3';
            }
        }
        else
        {
            return '3';
        }
    }
    else
    {
        return '3';
    }
}
char dt1b(double PL, double PW, double SW, double SL)
{
    if (PL < 2.55)
    {
        return '1';
    }
    else if (PW < 1.69)
    {
        if (PL < 4.85)
        {
            return '2';
        }
        else
        {
            return '3';
        }
    }
    else
    {
        return '3';
    }
}

double dt2b(double x1, double x2, double x3, int x4, int x5)
{
    if (x1 < 31.5)
    {
        if (x2 > -2.5)
            return 5.0;
        else if (x2 - 0.1 <= x1 && x1 <= x2 + 0.1)
            return 2.1;
        else
            return -1.1;
    }
    else if (-1 <= x3 && x3 <= 2)
        return 1.4;
    else if (x4 && x5)
        return -2.23;
    else
        return 11.0;
}

double dt2a(double x1, double x2, double x3, int x4, int x5)
{
    if (12 < x1 && x1 < 22)
    {
        if (x3 > 5 / 3)
            return -2.0;
        else if (x1 - 0.1 <= x3 && x3 <= x1 + 0.1)
            return 1.01;
        else
            return -8;
    }
    else if (x4 && x5)
        return -1;
    else if (-1 <= x2 && x2 <= 2)
        return -1 / 7;
    else
        return sqrt(2) / 3;
}

int dt3a(int debt, int year, char brand, char creditScore, char status)
{
    if (status == 'Y')
    {
        if (debt <= 10000 && creditScore != 'D' && creditScore != 'E')
        {
            if (creditScore == 'A' || creditScore == 'B')
            {
                if (debt / year / year < 2)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else if (brand == 'V' || brand == 'S' || brand == 'P')
            {
                if (debt / year / year < 2)
                {
                    return 2;
                }
                else
                {
                    return 3;
                }
            }
            else
            {
                return 4;
            }
        }
        else if (debt <= 100000 && creditScore != 'C' && creditScore != 'D' && creditScore != 'E')
        {
            if (creditScore == 'A' && year > 5)
            {
                return (2);
            }
            else if (brand == 'A' || brand == 'M' || brand == 'B')
            {
                return (4);
            }
            else
            {
                return (5);
            }
        }
        else
        {
            return (5);
        }
    }
    else
    {
        if (debt <= 10000 && creditScore != 'D' && creditScore != 'E')
        {
            if (brand == 'A' || brand == 'M' || brand == 'B')
            {
                if (debt / year < 3)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else if (brand == 'V' || brand == 'S' || brand == 'P')
            {
                if (debt / year < 3)
                {
                    return 2;
                }
                else if (debt / year < 5)
                {
                    return 3;
                }
                else
                {
                    return 4;
                }
            }
            else
            {
                return 4;
            }
        }
        else if (debt <= 100000 && creditScore != 'C' && creditScore != 'D' && creditScore != 'E')
        {
            if (creditScore == 'A' && year > 5)
            {
                return (2);
            }
            else if (brand == 'A' || brand == 'M' || brand == 'B')
            {
                return (3);
            }
            else if (year > 5)
            {
                return (4);
            }
            else
            {
                return 5;
            }
        }
        else
        {
            return (5);
        }
    }
}

int dt3b(int debt, int year, char brand, char creditScore, char status)
{
    if (debt <= 50000 && year > 5)
    {
        if (status == 'Y' && (brand == 'A' || brand == 'M' || brand == 'B'))
        {
            if ((creditScore == 'A' || creditScore == 'B') && year > 8)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (status == 'N' && (brand == 'V' || brand == 'S' || brand == 'P'))
        {
            if ((creditScore == 'A' || creditScore == 'B' || creditScore == 'C') || debt * debt / year < 5000)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 2;
        }
    }
    else if (year > 8)
    {
        if ((creditScore == 'A' || creditScore == 'B' || creditScore == 'C') || debt * debt / year < 5000)
        {
            return 3;
        }
        else if (status == 'N' && (creditScore == 'D' && creditScore == 'E'))
        {
            return 4;
        }
        else
        {
            return 5;
        }
    }
    else
    {
        return 5;
    }
}

/* Provide your implementations for all the requested functions here */