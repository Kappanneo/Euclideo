#include <stdio.h>
#include <string.h>
#include "klib.h"


int main(int argc, char *argv[])
{
  if(argc>2)
    {
      int a= deci(argv[1],strlen(argv[1]));
      int b= deci(argv[2],strlen(argv[2]));
      int vid= a > b? a : b;
      int vis= a > b? b : a; 
      while(vis)
	{
	  printf("%d= %d* %d+ %d\n",vid,vid/vis,vis,vid%vis);
	  int div= vis;
	  vis= vid%vis;
	  vid= div;
	}
      printf("MCD(%d,%d)= %d\n",a,b,vid);
    }
  return qualcosa(argc-2,"[numero] [numero]",argv[0]); 
}
