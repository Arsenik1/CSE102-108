#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

void stringg(char a);

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(double PL, double PW, double SW, double SL);
char dt1b(double PL, double PW, double SW, double SL);

double dt2b(double x1, double x2, double x3, int x4, int x5);
double dt2a(double x1, double x2, double x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(int debt,int year,char brand,char creditScore,char status);
int dt3b(int debt,int year,char brand,char creditScore,char status);

#endif /* _UTIL_H_ */