#include <stdio.h>
#include "milk.h"
#include <string.h>

//每添加一个指令，需要在control修改一次判定值

//控制输入规范
int control() { //打印店铺信息
    printf("____________________________________________\n");
    printf("||||||||||____欢迎光临肥猪流奶茶店____||||||||||\n");
    printf("1.menu\t\t2.revise\n3.check\t\t4.delete\n5.statistic\t6.quite\n7.output\n");
    printf("*****请输入序号:");
    //检测恶意输入
    int code, status;
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 7)) {
        if (status != 1)
            scanf("%*s"); //处理非整数输入
        printf("Enter an integer from 1to 6,please.\n");
    }
    return code;
}

//果汁菜单
int menu(int n) {
    // MILK dingDan;
    int a /*份数*/, b /*饮料编号*/;
    bigDD[n].num = n + 1;
    printf("---------------------------------------------------------\n");
    printf("订单编号:%5d (程序自动生成)\n", n + 1);
    printf("饮品名称:\n********************\n");
    printf("1.苹果汁\t10元一杯\n2.好果汁\t15元一杯\n");
    printf("3.伯伯奶茶\t17元一杯\n");
    printf("**请输入饮料编号:"), scanf("%d", &b), fflush(stdin); // add 饮料编号和名称
    //输入检测
    if (b < 1 || b > 3)
        printf("**请重新输入饮料编号:"), scanf("%d", &b), fflush(stdin);

    switch (b)                                                   //给订单添加信息
    {
        case 1:
            strcpy(bigDD[n].name, "苹果汁");
            bigDD[n].pri1 = 10;
            printf("请输入份数:"), scanf("%d", &bigDD[n].pri2), fflush(stdin);
            bigDD[n].pri3 = bigDD[n].pri2 * 10;
            printf("请添加备注:");
            scanf("%s", bigDD[n].remark);

            break;
        case 2:
            strcpy(bigDD[n].name, "好果汁");
            bigDD[n].pri1 = 15;
            printf("请输入份数:"), scanf("%d", &bigDD[n].pri2), fflush(stdin);
            bigDD[n].pri3 = bigDD[n].pri2 * bigDD[n].pri1;
            printf("请添加备注:");
            scanf("%s", bigDD[n].remark);
            break;

        case 3:
            strcpy(bigDD[n].name, "伯伯奶茶");
            bigDD[n].pri1 = 17;
            printf("请输入份数:"), scanf("%d", &bigDD[n].pri2), fflush(stdin);
            bigDD[n].pri3 = bigDD[n].pri2 * bigDD[n].pri1;
            printf("请添加备注:");
            scanf("%s", bigDD[n].remark);
            break;

            //模版
            // strcpy(bigDD[n].name, "<$$$>");
            // bigDD[n].pri1 = <$$$>;
            // printf("请输入份数:"), scanf("%d", &bigDD[n].pri2), fflush(stdin);
            // bigDD[n].pri3 = bigDD[n].pri2 * bigDD[n].pri1;
            // printf("请添加备注:");
            // scanf("%s", bigDD[n].remark);
        default:
            printf("请重新输入.\n");
            break;

    }

    //先储存信息再打印
    printf("---------------------------------------------------------\n");
    printf("已完成本次点单，点单信息如下:\n");
    printf("\t订单编号\t饮料名车\t  单价\t  份数\t  总价   \t备注\n");
    printf("************************************************\n");
    printf("\t  %4d\t %s\t%4d\t%4d\t%4d\t  %s\n", bigDD[n].num, bigDD[n].name, bigDD[n].pri1, bigDD[n].pri2,
           bigDD[n].pri3, bigDD[n].remark);
    printf("---------------------------------------------------------\n");

    fflush(stdin);
}

//修改订单
int revise(int n) {
    int a; //修改订单编号
    int b; //循环变量
    printf("请输入待修改订单编号:"), scanf("%d", &a);
    for (b = 0; b < n; b++) {
        if (bigDD[b].num == a) //判断是否找到订单编号，开始修改
        {
            printf("请输入修改后的份数:"), scanf("%d", &bigDD[b].pri2);
            bigDD[b].pri3 = bigDD[b].pri1 * bigDD[b].pri2;
            printf("请输入修改的备注:"), scanf("%s", bigDD[b].remark), fflush(stdin);
            printf("修改后订单信息如下:\n");
            printf("\t  %4d\t %s\t%4d\t%4d\t%4d\t  %s\n", bigDD[b].num, bigDD[b].name, bigDD[b].pri1, bigDD[b].pri2,
                   bigDD[b].pri3, bigDD[b].remark);
        } else;
    }

    fflush(stdin);
}

int check(int n) {
    int i;
    printf("######################################\n");
    printf("开始打印订单信息:\n");
    printf("\t订单编号\t饮料名车\t  单价\t  份数\t  总价   \t备注\n");
    for (i = 0; i < n; i++) {
        printf("\t  %4d\t %s\t   %d\t  %d\t %d\t  %s\n", bigDD[i].num, bigDD[i].name, bigDD[i].pri1, bigDD[i].pri2,
               bigDD[i].pri3, bigDD[i].remark);
    }
    printf("######################################\n");

    fflush(stdin);
}

int delete(int n) {
    //先查找
    int a;  //查找订单编号
    int b;  //循环变量
    char c; //判断是否删除的变量
    printf("请输入删除的订单编号:"), scanf("%d", &a);
    fflush(stdin); //清空
    for (b = 0; b < n; b++) {
        if (bigDD[b].num == a) //找到之后开始删除
        {
            printf("是否删除(y/n):"), scanf("%c", &c);
            fflush(stdin);
            if (c == 'y' || c == 'Y') {
                strcpy(bigDD[b].name, "订单已删除");
                bigDD[b].pri1 = bigDD[b].pri2 = bigDD[b].pri3 = 0;
                strcpy(bigDD[b].remark, "订单已删除");
                printf("删除成功\n");
                printf("----------------------------------------------------------\n");
            } else
                printf("----------------------------------------------------------\n");
        } else;
    }

    fflush(stdin);
}

int statistic(int n) //查询某一个订单的信息
{
    //先查找
    int a;  //查找的订单编号
    int b;  //循环变量
    char c; //用来判断订单是否删除
    printf("请输入想查找的订单编号:"), scanf("%d", &a);
    fflush(stdin);
    for (b = 0; b < n; b++) {
        if (bigDD[b].num == a) {
            if (bigDD[b].pri1 != 0) {
                printf("---------------------------------------------------------\n");
                printf("\t订单编号\t饮料名车\t  单价\t  份数\t  总价   \t备注\n");
                printf("\t  %4d\t %s\t%4d\t%4d\t%4d\t  %s\n", bigDD[b].num, bigDD[b].name, bigDD[b].pri1, bigDD[b].pri2,
                       bigDD[b].pri3, bigDD[b].remark);
                printf("---------------------------------------------------------\n");
                break;
            }
                // if (bigDD[b].pri1 == 0)
            else {
                printf("订单已删除。\n");
                break;
            }
            // else
            //     ;
        } else;
        // printf("没有此订单\n");
    }
    fflush(stdin);
}

int output(int n) {
    FILE *fp1;
    int i;
    fp1 = fopen("./milk.txt", "w"); //
    //./milk.txt
    if (fp1 == NULL) {
        printf("errr");
    }
    fprintf(fp1, "\t订单编号\t饮料名车\t  单价\t  份数\t  总价   \t备注\n");
    for (i = 0; i < n; i++) {
        fprintf(fp1, "\t  %4d\t %s\t%4d\t%4d\t%4d\t  %s\n", bigDD[i].num, bigDD[i].name, bigDD[i].pri1, bigDD[i].pri2,
                bigDD[i].pri3, bigDD[i].remark);
    }
    fclose(fp1);
    printf("导出成功。\n");
    return 0;
}