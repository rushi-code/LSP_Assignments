#include<stdio.h>
#include "sharedfile.h"

void DisplayInfo(int fd)
{
    struct stat sobj;
    fstat(fd,&sobj);

    printf("Information of given file\n");

    printf("Inode : %ld\n",sobj.st_ino);
    printf("Size : %ld\n",sobj.st_size);
    printf("LinkCount : %ld\n",sobj.st_nlink);
    printf("Blocks : %ld\n",sobj.st_blocks);
    printf("Block Size  : %ld\n",sobj.st_blksize);


}
