#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *pdir;
    struct dirent *pde;
    int i =0, cnt =0;
    char name_list[10][256];

    if(argc <2)
    {
        fprintf(stderr, "Usage:file_dir dirname\n");
        exit(1);
    }

    if((pdir = opendir(argv[1])) <0)
    {
        perror("opendir");
        exit(1);
    }

    while((pde = readdir(pdir)) != NULL)
    {
        if(pde ->d_name[0] == '.')
            continue;

        printf("%s ", pde ->d_name);
        if(pde->d_type ==4)
        {
            strcpy(name_list[cnt], pde->d_name);
            cnt++;
        }
    }
    closedir(pdir);

    for(i=0;i<cnt;i++)
    {
        pdir = opendir(name_list[i]);
        printf("\n%s : \n",name_list[i]);
        while((pde = readdir(pdir)) != NULL)
                printf("%s ", pde->d_name);
        printf("\n\n");
    }
    closedir(pdir);
}
