#include "stdio.h"
#include "stdlib.h"
#include "../file/file.h"
typedef struct
{
    int num;
    char question[100];
    char choose[30];
    char answer;
    char analyse[100];
    int mark;
} IMP;

void ques_main(char file_ques_id[]); //给其他函数的接口
// int analyze_ques(IMP ask__6[], int mar5);                                            //给出解析 5
void save_ques(IMP ask[], int mar_save, char file_ques_savename[], int *continue_status_sa);                 //保存数据
int wrong_ques(IMP ask__5[], int mar4, int *ques_status4, char file_ques_name4[], int *continue_status4);    //做错题  4
int check_ques(IMP ask__4[], int mar3);                                                                      //查分   3
int continue_ques(IMP ask__3[], int mar2, int *ques_status2, int *continue_status2, char file_ques_name2[]); //继续做题  2
int head_ques(IMP ask__2[], int mar1, int *ques_status1, int *continue_status1, char file_ques_name1[]);     //从头做题  1
int menu();                                                                                                  //菜单
int center(IMP ask[], int mar, int *ques_status_center, int *continue_status, char file_ques_centername[]);  //调度中心，调用其他函数
void check_in(char *ar);