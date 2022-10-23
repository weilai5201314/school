#include "ques.h"

//目前问题：如何防止小数输入，输入小数会自动取整
//还想将读写文件写成模块函数,但是出了些问题

void ques_main(char file_ques_id[])
{
    int i = 0;               //主函数计数变量，会多次使用，需要注意每次使用前是否清零
    int mar = 0;             //记录读取了多少题
    FILE *ptr1;              //文件指针
    int ques_status = 0;     //记录做题状态 //给 4 5 函数
    int continue_status = 0; //专门在 做题和继续做题之间，判断是否继续做题
    int file_ques_status = 0;
    char file_ques_name[20] = {0}; // sprintf之后的文件名,作为备份文件名

    //分配动态数组空间
    int mar_1 = 0;
    IMP *ask;
    ptr1 = fopen("./ques/data.txt", "r");
    if (ptr1 == NULL)
        printf("401\n");
    fscanf(ptr1, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n"), fscanf(ptr1, "%d\n", &continue_status);
    //遍历，获取数组大小
    for (i = 0; !feof(ptr1); i++)
        fscanf(ptr1, "%*d\t%*s\t%*s\t%*c\t%*s\t%*d\n"), mar_1++;
    fclose(ptr1);
    ask = (IMP *)malloc(mar_1 * sizeof(IMP)); //开始分配
    printf("%d\n", mar_1);
    if (ask == NULL)
        printf("获取失败。\n");

    //处理文件
    file_ques_status = file_main(file_ques_id); //调用file文件，遍历确定文件名

    if (file_ques_status) // 1读取备份
    {
        sprintf(file_ques_name, "./ques/%s.txt", file_ques_id);

        ptr1 = fopen(file_ques_name, "r");
        if (ptr1 == NULL)
            printf("401\n");
        else
            printf("ques_main 导入beifen成功\n");
        fscanf(ptr1, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");
        fscanf(ptr1, "%d\n", &continue_status);
        for (i = 0; !feof(ptr1); i++)
        {
            fscanf(ptr1, "%d\t%s\t%s\t%c\t%s\t%d\n", &ask[i].num, ask[i].question, ask[i].choose, &ask[i].answer,
                   ask[i].analyse, &ask[i].mark);
            mar++;
        }
        fclose(ptr1);
        //    测试导入结果
        //    for (i = 0; i < 5; i++)
        //        printf("%d\t%s\t%s\t%c\t%s\t%d\n", ask[i].num, ask[i].question, ask[i].choose, ask[i].answer, ask[i].analyse, ask[i].mark);
    }
    else // false创建新文件
    //并修改后续保存地址
    {
        sprintf(file_ques_name, "./ques/%s.txt", file_ques_id);
        // printf("%s", file_ques_name);
        ptr1 = fopen("./ques/data.txt", "r");
        if (ptr1 == NULL)
            printf("401\n");
        else
            printf("ques_main 导入成功\n");
        fscanf(ptr1, "%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");
        fscanf(ptr1, "%d\n", &continue_status);
        for (i = 0; !feof(ptr1); i++)
        {
            fscanf(ptr1, "%d\t%s\t%s\t%c\t%s\t%d\n", &ask[i].num, ask[i].question, ask[i].choose, &ask[i].answer,
                   ask[i].analyse, &ask[i].mark);
            mar++;
        }
        fclose(ptr1);
    }
    //    开始执行
    center(ask, mar, &ques_status, &continue_status, file_ques_name);
    free(ask);
}

// 5
// int analyze_ques(IMP ask__6[], int j) //写这个函数时，想把做错题函数一起调用进来，或者将解析功能加进做题函数
// {                                     //但是似乎都是做完了题目才给解析，因此单独当一个模块，复制错题函数的部分模块
//     int wrong = 1;                    //记录错题数量
//     for (int i = 0; i < j; i++)       //找题
//     {
//         if (ask__6[i].mark == 0)
//         {
//             puts("还有题目未完成，请先完成。");
//             return 0;
//         }

//         if (ask__6[i].mark == 2) //找题
//         {
//             printf("%d\t%s\n", ask__6[i].num, ask__6[i].question);
//             printf("正确答案:%c\n", ask__6[i].answer);
//             fputs("解析:", stdout);
//             puts(ask__6[i].analyse);
//             fputs("\n", stdout);
//             wrong = 0;
//         }
//     }
//     if (wrong)
//         puts("没有错题！");
//     return 0;
// }

// 4
int wrong_ques(IMP ask__5[], int mar5, int *ques_status4, char file_ques_name4[], int *continue_status4) //做错题，因为不能确定，选择遍历然后找到一题打印一题
{
    char choose;
    char wq_ans;   //记录答案
    int wrong = 1; //记录错题数量
    // puts("错题:");

    //判断题目是否做完
    if (*ques_status4 == 0)
    {
        puts("4 请先完成题目.");
        return 0;
    }

    for (int i = 0; i < mar5; i++) //找题，做题，然后重新标记
    {
        // if (ask__5[i].mark == 0)
        // {
        //     puts("还有题目未完成，请先完成。");
        //     return 0;
        // }
        if (ask__5[i].mark == 2) //找题
        {
            printf("%d\t%s\t%s\n", ask__5[i].num, ask__5[i].question, ask__5[i].choose);
            scanf("%c", &wq_ans), fflush(stdin); //获取选项
            if (wq_ans == ask__5[i].answer || wq_ans == ask__5[i].answer + 32)
            {
                puts("正确。");
                ask__5[i].mark = 1;
            }
            // if (wq_ans != ask__5[i].answer && wq_ans != ask__5[i].answer + 32)
            else
            {
                printf("错误，正确答案是%c\n解析:%s\n", ask__5[i].answer, ask__5[i].analyse);
                ask__5[i].mark = 2;
            }
            printf("继续做题吗?(Y/N)"), check_in(&choose);
            if (choose == 'N' || choose == 'n')
            {
                save_ques(ask__5, mar5, file_ques_name4, continue_status4);
                return 0;
            }
            else
                // if (choose == 'Y' || choose == 'y')
                save_ques(ask__5, mar5, file_ques_name4, continue_status4);
            wrong = 0;
        }
    }
    if (wrong)
        printf("没有错题!\n");
    save_ques(ask__5, mar5, file_ques_name4, continue_status4);
    return 0;
}

// 3
int check_ques(IMP ask__4[], int mar4)
{
    float storage = 0; //存放正确题目数量
    for (int i = 0; i < mar4; i++)
    {
        if (ask__4[i].mark == 0)
        {
            printf("还有未做完的题目，请先答题。\n");
            return 0;
        }
        if (1 == ask__4[i].mark)
            storage++;
    }
    //计算得分及打印
    float gard;
    gard = storage / mar4; //只需要一个float即可替换整数类型
    printf("对了%.0f道，错了%.0f道，正确率为%.2f%%.\n", storage, mar4 - storage, gard * 100);
    return 0;
}

void save_ques(IMP ask[], int mar_save, char file_ques_savename[], int *continue_status_sa) //保存数据到文本
{
    // static char file_path_name[20];
    int i;
    FILE *ptr2;
    ptr2 = fopen(file_ques_savename, "w");
    if (ptr2 == NULL)
        printf("save_ques 导入失败");
    // else
    //     puts("200");//测试是否能打开文件
    fprintf(ptr2, "题号	题目	选项	答案	解析	备注\n");
    fprintf(ptr2, "%d\n", *continue_status_sa);
    for (i = 0; i < mar_save; i++)
        fprintf(ptr2, "%d\t%s\t%s\t%c\t%s\t%d\n", ask[i].num, ask[i].question, ask[i].choose, ask[i].answer,
                ask[i].analyse, ask[i].mark);
    fclose(ptr2);
    puts("save_ques 保存成功");
}

// 2
int continue_ques(IMP ask__3[], int mar2, int *ques_status2, int *continue_status2, char file_ques_name2[]) //不太确定继续做题是从哪开始继续，姑且认为是给定的数据已经做了一部分
{                                                                                                           //读数据然后开始继续做题
    FILE *ptr1;
    int x = 0;   //判断多少题已经做了
    char ans;    //选项
    char choose; // yse no option

    if (*continue_status2 == 0)
    {
        puts("请从头开始");
        return 0;
    }
    ptr1 = fopen("./ques/data.txt", "r");
    if (ptr1 == NULL)
        printf("导入失败");
    // for (int i = 0; i < 5; i++) //测试是否读取
    // printf("%d\t%s\t%s\t%c\t%s\t%d\n", ask__3[i].num, ask__3[i].question, ask__3[i].choose, ask__3[i].answer, ask__3[i].analyse, ask__3[i].mark);
    for (int i = 0; i < mar2; i++)
    {
        if (ask__3[i].mark == 0)
        {
            printf("%d\t%s\t%s\n", ask__3[i].num, ask__3[i].question, ask__3[i].choose);
            scanf("%c", &ans), fflush(stdin); //获取选项
            //比较答案并且标记
            if (ans == ask__3[i].answer || ans == ask__3[i].answer + 32)
            {
                puts("正确。");
                ask__3[i].mark = 1;
            }
            // if (ans != ask__3[i].answer && ans != ask__3[i].answer + 32)
            else
            {
                printf("错误，答案是%c\n解析:%s\n", ask__3[i].answer, ask__3[i].analyse);
                ask__3[i].mark = 2;
            }
            printf("是否继续做题？(Y/N)"), check_in(&choose);
            if (choose == 'N' || choose == 'n')
            {
                save_ques(ask__3, mar2, file_ques_name2, continue_status2);
                return 0;
            }
            else
                // if (choose == 'Y' || choose == 'y')
                save_ques(ask__3, mar2, file_ques_name2, continue_status2);
        }
        else
            x++;
    }
    if (x == mar2)
        puts("全都已完成,无需做题.");
    //赋值状态值
    *ques_status2 = 1;
    // save_ques(ask__3, mar2);
    return 0;
}

// 1    状态值status只有在全部做完之后才能赋1
//      而continue_status 则是在做了一题之后就赋值
int head_ques(IMP ask__2[], int mar1, int *ques_status1, int *continue_status1, char file_ques_name1[])
{
    char ans;
    char choose;
    int i;
    //先将所有标记清零,且保存导入
    for (i = 0; i < mar1; i++)
        ask__2[i].mark = 0;
    save_ques(ask__2, mar1, file_ques_name1, continue_status1);
    //再将所有状态status归零
    *ques_status1 = 0;
    *continue_status1 = 0;

    //打印题目
    for (i = 0; i < mar1; i++) //打印题目选项
    {                          //确保continue_ques函数可运行
        *continue_status1 = 1;

        printf("%d\t%s\t%s\n", ask__2[i].num, ask__2[i].question, ask__2[i].choose);
        scanf("%c", &ans), fflush(stdin); //获取选项
        //比较答案并且标记
        if (ans == ask__2[i].answer || ans == ask__2[i].answer + 32)
        {
            puts("正确。");
            ask__2[i].mark = 1;
        }
        // if (ans != ask__2[i].answer && ans != ask__2[i].answer + 32)
        else
        {
            printf("错误，正确答案是%c\n解析:%s\n", ask__2[i].answer, ask__2[i].analyse);
            ask__2[i].mark = 2;
        }
        // printf("%d\n", ask__2[i].mark);//测试是否改变标记
        printf("继续做题吗？(Y/N)"), check_in(&choose);
        //        printf("继续做题吗？（Y/N）"), scanf("%c",&choose), fflush(stdin);
        if (choose == 'N' || choose == 'n')
        {
            save_ques(ask__2, mar1, file_ques_name1, continue_status1);
            return 0;
        }
        else
            // if (choose == 'Y' || choose == 'y')
            save_ques(ask__2, mar1, file_ques_name1, continue_status1);
    }
    //做完题目之后需要保存
    // save_ques(ask__2, mar1);
    //状态值赋1
    *ques_status1 = 1;

    return 0;
}

int menu() //打印菜单，检查恶意输入
{
    printf("\033[01;35m ");
    puts("\n***********");
    puts("1.从头开始刷题");
    puts("2.继续刷题");
    puts("3.查分");
    puts("4.刷错题");
    // puts("5.查看错题解析");
    puts("5.退出刷题系统");
    puts("***********");
    puts("请输入菜单号:");
    int code, status;
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5)) //修改这里的范围，再修改下面提示语
    {
        if (status != 1)
            scanf("%*s"); //处理非整数输入
        printf("Enter an integer from 1to 5,please.\n");
    }
    fflush(stdin);
    puts("______________________");
    printf("\033[0m\n");
    return code;
}

int center(IMP ask[], int mar, int *ques_status_center, int *continue_status, char file_ques_centername[])
{
    int code = 0;
    for (;;)
    {
        code = menu();
        switch (code)
        {
        case 1:
            head_ques(ask, mar, ques_status_center, continue_status, file_ques_centername);
            break;
        case 2:
            continue_ques(ask, mar, ques_status_center, continue_status, file_ques_centername);
            break;
        case 3:
            check_ques(ask, mar);
            break;
        case 4:
            wrong_ques(ask, mar, ques_status_center, file_ques_centername, continue_status);
            break;
        case 5:
            // analyze_ques(ask, mar);
            // break;

            return 0;
        // case 6:
        //     return 0;
        default:
            break;
        }
    }
}

//检测字符串输入
void check_in(char *ar)
{
    while (1)
    {
        scanf("%c", ar), fflush(stdin);
        if (*ar == 'Y' || *ar == 'y' || *ar == 'N' || *ar == 'n')
            break;
        else
            printf("请重新输入\n");
    }
    // return *ar;
}
