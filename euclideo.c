#include <stdio.h>
#include "../klib.h"


int main(int argc, char *argv[])
{
  if(argc>2)
    {
      long a= unint(argv[1]);
      long b= unint(argv[2]);
      long vid= a > b? a : b;
      long vis= a > b? b : a;
      int q;
      int s[2]; s[0]=1; s[1]=0;
      int t[2]; t[0]=0; t[1]=1;
      long temp;

      while(vis)
	{
	  q= vid/vis;

	  temp= s[1];
	  s[1]= s[0]-q*s[1];
	  s[0]= temp;

	  temp= t[1];
	  t[1]= t[0]-q*t[1];
	  t[0]= temp;

	  printf("%ld= %d* %ld+ %ld (%d, %d)\n",vid,q,vis,vid%vis,s[0],t[0]);

	  temp= vis;
	  vis= vid%vis;
	  vid= temp;
	}
      
      printf("\nMCD(%ld,%ld)= %ld\n",a,b,vid);
    }

  return qualcosa(argc-2,"[numero] [numero]",argv[0]); 
}
