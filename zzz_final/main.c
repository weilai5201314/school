#include "login/login.h"
#include "ques/ques.h"
#include "file/file.h"
//后续修改为链表存储，demo先行数组
int main(void)
{
    int count = 0; //记录人员个数
    LOG wm[10];    //登录人员信息
    int order = 0;
    char File_main_id[10] = {0};

    //导入登录信息
    count = input(wm);

    // control(wm, count, &order);
    int i = 0;
    int status2 = 0;
    int code;

    // for (i = 6; i < 41; i++)
    // {
    //     printf("%d\t取余运算3.4%%3非法	(A)对(B)错	A	浮点数不能参与取余%%运算	0\n", i);
    // }

    for (;;)
    {
        puts("\033[01;34m");
        puts("1 登陆\n2 退出登陆\n3 退出系统\n4 刷题系统\n请输入菜单号:");
        printf("\033[0m");
        //控制输入
        while ((code = scanf("%d", &i)) != 1 || (i < 1 || i > 4))
        {
            // fflush(stdin);
            if (!code)
                scanf("%*s");
            puts("Please enter 1 to 4.");
        }
        fflush(stdin);
        switch (i)
        {
        case 1:
            status2 = menu_admin(wm, count, status2, &order, File_main_id);
            printf("file id  %s", File_main_id);
            break;
        case 2:
            status2 = log_out(wm, status2, &order);
            // printf("now %d", status2);
            break;
        case 3:
            if (status2)
            {
                puts("请先退出登录！");
                break;
            }
            else
                return 0;
        case 4:
            if (status2)
                ques_main(File_main_id);
            else
                puts("请先登录.");
            break;
        default:
            puts("Please enter again.");
            break;
        }
    }

    return 0;
}