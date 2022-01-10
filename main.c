#include "get_next_line.h"


int main()
{
   char *str;
   int fd1 = open("file1.txt", O_RDONLY);
   int fd2 = open("file2.txt", O_RDONLY);
   printf("fd = %d\t%s",fd1,get_next_line(fd1));
   printf("fd = %d\t%s",fd2,get_next_line(fd2));
   //stdin
   printf("%s",get_next_line(0));
   //Loop
   while((str = get_next_line(fd1)))
      printf("%s", str);

}



int main(int ac, char *av[])
{
   ac =0;
   int fd1 = open(av[1], O_RDONLY);
   printf("%s",get_next_line(fd1));
   // give the name of the file after <<./a.out>>
}