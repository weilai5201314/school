#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main()
{
    DIR *dir;
    struct dirent *ptr;
    dir = opendir("./");
    while ((ptr = readdir(dir)) != NULL)
    {
        printf("d_name:%s\n", ptr->d_name);
    }
    closedir(dir);
    return 0;
}