#ifndef MILK_MILK_H
#define MILK_MILK_H
#endif // MILK_MILK_H
//输入检测
int control();
//定义存储信息
struct milk
{
    int num;          //订单号
    char name[30];    //名称
    int pri1;         //单价
    int pri2;         //份数
    int pri3;         //总价
    char remark[100]; //备注
};
typedef struct milk MILK;

MILK bigDD[100000]; //订单集合，全局数组

int menu(int n);
int revise(int n);
int check(int n);
int delete (int n);
int statistic(int n);
int output(int n);
