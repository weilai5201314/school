//关于此文件的函数，应该在用户登录和调取题目之间，登录的时候调用
//任务：比对用户登录，选择创建还是备份文件
#include "file.h"
int file_main(char file_file_id[])
{
    DIR *dir1 = NULL;                //文件夹
    int i;                           // for循环
    int file_num = 0;                //记录文件数量
    struct dirent *file_name = NULL; //存储文件地址
    struct dirent data[50];          //分配用户文件 //当用户数量变动时修改
    // char usr_id[10];                 //用户输入，用来对比文件名
    // char file_file_name[20] = {0};   //文件名
    int file_status = 0;
    //判断文件夹打开
    if ((dir1 = opendir("./ques")) == NULL)
    {
        puts("Open dir error.");
        return -1;
    }
    //遍历存储文件名
    for (i = 0; (file_name = readdir(dir1)) != NULL; i++)
    {
        strcpy(data[i].d_name, file_name->d_name);
        // printf("%s\t", data[i].d_name);
        file_num++;
    }
    closedir(dir1);
    //输入对比
    // printf("input:"), scanf("%s", usr_id), fflush(stdin);
    for (i = 0; i < file_num; i++)
    {
        if (strncmp(file_file_id, data[i].d_name, 4) == 0)
        { // printf("%s\n", data[i].d_name);
            // sprintf(file_file_name, "./ques/%s.txt", file_file_id);
            file_status = 1;
            break;
        }
        else
        {
            // sprintf(file_file_name, "touch ./ques/%s.txt", file_file_id);
            // system(file_file_name);
            file_status = 0;
        }
    }
    return file_status;
}

// 1
// int file_compare()
// {
//     ;
// }