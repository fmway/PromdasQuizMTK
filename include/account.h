#ifndef ACCOUNT_H_
#define ACCOUNT_H_

/* Login function */
int login(char (*usernames)[100], char (*passwords)[100], int *len_user);

/* Registration Function */
int reg(char (*usernames)[100], char (*names)[100], char (*passwords)[100], int *len_user);

#endif // !ACCOUNT_H_
