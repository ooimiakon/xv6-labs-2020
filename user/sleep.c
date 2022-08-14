#include "kernel/types.h"
#include "user.h"


// int main(int argc,char* argv[])
// argc 是命令行总的参数个数  
// argv[] 是 argc 个参数，其中第 0 个参数是程序的全名，以后的参数是命令行后面跟的用户输入的参数

int main(int argc,char* argv[])
{
   if(argc != 2)
   {
     // user/printf.c 中的 fprintf(int fd, const char *fmt, ...) 函数进行格式化输出
     // 参数 fd 是文件描述符，0 表示标准输入，1 表示标准输出，2 表示标准错误
      fprintf(2,"Only 2 argument is needed!\n");
      exit(1);
   }

   // atoi把字符串型参数转换为整型
   int ticks=atoi(argv[1]);
   sleep(ticks);
   exit(0);
}