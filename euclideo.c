#include <stdio.h>
#include <string.h>
#include "klib.h"


int main(int argc, char *argv[])
{
  if(argc>1)
  {
    int vid= deci(argv[1],strlen(argv[1]));
    int vis= deci(argv[2],strlen(argv[2]));
    while(vis!=0)
	{
	  int div= vis;
	  vis= vid%vis;
	  vid= div;
	}
    printf("MCD(%d,%d)= %d\n",deci(argv[1],strlen(argv[1])) ,deci(argv[2],strlen(argv[2])), vid);
  }
  return qualcosa(argc-1,"[dividendo] [divisore]",argv[0]); 
}
