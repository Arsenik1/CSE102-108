#ifndef _UTIL_H_
#define _UTIL_H_

int find_divisible(int x, int y, int z);

int find_nth_divisible(int n, int f_I, int z);

int create_customer(char identity_number [ ], int password);

int validate_identity_number(char identity_number []);

int check_login(char identity_number [ ], int password);

int withdrawable_amount(float cash_amount);


#endif /* _UTIL_H_ */
