#ifndef MY_PAGES_H
#define MY_PAGES_H

/* Clear screen */
void clear();

/* Logout menu */
int logout(void);


/* Start a Program */
int start(char (*username_admins)[100], char (*name_admins)[100], char (*password_admins)[100], int *len_admins, char (*username_users)[100], char (*name_users)[100], char (*password_users)[100], int *len_users, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);

/* Menu for User */
int menu_user(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level, const int id_user);

/* Menu for Admin */
int menu_admin(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);

#endif // !MY_PAGES_H
