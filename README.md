# PromdasQuizMTK

###Struct
```c
typedef struct Time {
  int hours;
  int minutes;
  int seconds;
} Time;
```
###Fungsi
```c
int login(char (*usernames)[100], char (*passwords)[100], int *len_user);
int reg(char (*usernames)[100], char (*names)[100], char (*passwords)[100], int *len_user);
Time gettimenow(void);
Time diftime(Time time_1, Time time_2);
int toseconds(Time time);
void clear();
int logout(void);
int start(char (*username_admins)[100], char (*name_admins)[100], char (*password_admins)[100], int *len_admins, char (*username_users)[100], char (*name_users)[100], char (*password_users)[100], int *len_users, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);
int menu_user(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level, const int id_user);
int menu_admin(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);
void run_questions(char **questions, char *(*choices)[4], char *keys, int *score, const int len_questions);
void level_questions(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int *scores, int *time_plays, const int level);
void print_questions(char **questions, const int len_questions);
void print_choices(char **choices, const int len_choices);
void print_keys(char *keys, const int len_keys);
void print_score(char *name, char *username, int *score, int *time_plays, const int level);
int update_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level);
int get_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], const int level);
int get_data(char (*usernames)[100], char (*names)[100], int *len_user, int (*scores)[], int (*time_plays)[], const int level);
void getpasswd(const char * prompt, char * dest);
void read_line(char * dest);
void getsv(char * dest);
```
