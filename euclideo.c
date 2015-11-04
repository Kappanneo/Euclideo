#include <stdio.h>
#include "../klib.h"


int main(int argc, char *argv[])
{
  if(argc>2)
    {
      long a= deci(argv[1],strl(argv[1]));
      long b= deci(argv[2],strl(argv[2]));
      long vid= a > b? a : b;
      long vis= a > b? b : a; 
      while(vis)
	{
	  printf("%ld= %ld* %ld+ %ld\n",vid,vid/vis,vis,vid%vis);
	  long div= vis;
	  vis= vid%vis;
	  vid= div;
	}
      printf("MCD(%ld,%ld)= %ld\n",a,b,vid);
    }
  return qualcosa(argc-2,"[numero] [numero]",argv[0]); 
}
