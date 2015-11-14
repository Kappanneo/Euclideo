#include <stdio.h>
#include "../klib.h"


int main(int argc, char *argv[])
{
  if(argc>2)
    {
      long a= unint(argv[1]);
      long b= unint(argv[2]);
      long a2= a >= 0? a: -a;
      long b2= b >= 0? b: -b;
      long vid= a2 > b2? (argc==3? a2: a): (argc==3? b2: b);
      long vis= a2 > b2? (argc==3? b2: b): (argc==3? a2: a);
      int q;
      int s[]={1,0};
      int t[]={0,1};
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

	  printf("%ld= %d* %ld %c%ld ", vid, q, vis, vid%vis<0?:'+', vid%vis);
	  if(argc==4)if(unint(argv[3])!=0)
	    printf("(%d, %d)", s[0], t[0]);
	  puts("");

	  temp= vis;
	  vis= vid%vis;
	  vid= temp;
	}

      printf("\nMCD(%ld,%ld)= %ld\n\n",a,b,vid >0? vid: -vid);

      if(argc==4)if(unint(argv[3])!=0)
	{
	  long c= unint(argv[3]);
	  printf("%ldx %c%ldy =%ld", a, b<0?:'+', b, c);
	  printf("%sha soluzioni\n\n", c%vid?" non ":" ");
	  
	  if(c%vid==0)
	    {
	      long xo= a2 > b2? s[0]*c/vid : t[0]*c/vid;
	      long yo= a2 > b2? t[0]*c/vid : s[0]*c/vid;

	      printf("x= %ld %c%ldk\n", xo, b/vid<0?:'+', b/vid); 
	      printf("y= %ld %c%ldk\n\n", yo, a/vid>0?:'+', -a/vid);
	    }
	}
    }
  return qualcosa(argc-2,"[a] [b] [c] (ax+by=c)",argv[0]); 
}
