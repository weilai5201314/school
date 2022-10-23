#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct data
{
    char order[10];
    char pass[10];
    char admin[20];
} LOG;

void save_admin(LOG wm5[], int status5, int *order5);                                  // 5
int log_out(LOG wm4[], int status4, int *order4);                                      // 4
int menu_admin(LOG wm3[], int count3, int status3, int *order3, char file_login_id3[]); // 3
// int control(LOG wm2[], int count2, int *order2);                 // 2
int input(LOG wm1[]); // 1
