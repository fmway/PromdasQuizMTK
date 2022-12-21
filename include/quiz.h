#ifndef MY_QUIZ_H
#define MY_QUIZ_H

//Run questions (array 2d)
void run_questions(char **questions, char *(*choices)[4], char *keys, int *score, const int len_questions);


// run questions (array 3d)
void level_questions(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int *scores, int *time_plays, const int level);

/* Print questions */
void print_questions(char **questions, const int len_questions);

/* Print choice of Questions */
void print_choices(char **choices, const int len_choices);

/* Print keys of Questions */
void print_keys(char *keys, const int len_keys);

/* Print scores */
void print_score(char *name, char *username, int *score, int *time_plays, const int level);

/* Update Questions, Choices, and Keys */
int update_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);

/* Get data of questions, Choices and Keys */
int get_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], const int level);

/* Get details all users */
int get_data(char (*usernames)[100], char (*names)[100], int *len_user, int (*scores)[], int (*time_plays)[], const int level);

#endif // !MY_QUIZ_H

