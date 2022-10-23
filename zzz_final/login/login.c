// bug：
//  3函数，密码比对部分
#include "login.h"

// 5 保存登陆日志
void save_admin(LOG wm5[], int status5, int *order5)
{
    FILE *ptr5;
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow = localtime(&now);
    ptr5 = fopen("./login/backup.txt", "a");
    if (ptr5 == NULL)
        puts("保存失败.");
    fprintf(ptr5, "%s\t%s\t%d\t%s", wm5[*order5].order, wm5[*order5].admin, status5, asctime(timenow));
    fclose(ptr5);
    // printf("\n备份成功!\n");
}

// 4 退出
int log_out(LOG wm4[], int status4, int *order4)
{
    if (!status4)
    {
        puts("请先登录。");
        return status4;
    }
    status4 = 0;
    // printf("4xxx %d\n", order4);
    save_admin(wm4, status4, order4);
    puts("退出成功。");
    return status4;
}
// 3 登陆界面
int menu_admin(LOG wm3[], int count3, int status3, int *order3, char file_login_id3[])
{
    if (status3)
    {
        puts("已登录。");
        return status3;
    }
    int i = 0;
    char ID_order[10] = {0};
    char *ID_pass = NULL;
    printf("\033[36m");
    puts("请输入 ID号:"), scanf("%s", ID_order), fflush(stdin);
    ID_pass = getpass("请输入密码:"), fflush(stdin);
    printf("\033[0m");
    //判断密码
    for (i = 0; i < count3; i++)
    {
        // printf("原来%s\n", wm3[i].order); //测试
        // if (bcmp(ID_order, wm3[i].order, 7) == 0 && bcmp(ID_pass, wm3[i].pass, 7) == 0)
        if (*(ID_order + 3) == *(wm3[i].order + 3) && bcmp(ID_pass, wm3[i].pass, 7) == 0)
        {
            printf("\033[01;37m登陆成功,当前ID:%s,身份:%s\n", wm3[i].order, wm3[i].admin);
            //保存
            status3 = 1;
            *order3 = i;
            strcpy(file_login_id3, wm3[i].order);//获取登录id
            // printf("prder %d", *order3);
            save_admin(wm3, status3, order3);
            return status3;
        }
        else
            continue;
    }
    //遍历
    puts("\033[01;31m登陆失败。");
    return 0;
}

// 2 控制中心
// int control(LOG wm2[], int count2, int *order2)
// {

// }

// 1 导入
int input(LOG wm1[])
{
    FILE *ptr1;
    int i = 0;
    int count1 = 0;
    ptr1 = fopen("./login/usrcode.txt", "r");
    if (ptr1 == NULL)
        puts("导入错误");
    printf("开始读取...\n");
    fscanf(ptr1, "%*s\t%*s\t%*s\n");
    for (i = 0; !feof(ptr1); i++)
    {
        fscanf(ptr1, "%s\t%s\t%s\n", wm1[i].order, wm1[i].pass, wm1[i].admin);
        count1++;
        // printf("%s\t%s\t%s\n", wm1[i].order, wm1[i].pass, wm1[i].admin); //测试读取
    }
    fclose(ptr1);
    printf("login_input 读取成功!\n");
    return count1;
}
