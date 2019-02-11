# include <stdio.h>

int c=100,d;/* c is an initialised global variable and d is an uninitialized global variable*/
/* c- data segment and d - bss segment*/
int fun(int arg1,int arg2)/* stack-arg1 & arg2*/
{
	static int count=0;/*count - datasegment*/
	count++;
	return count+c;
}


main()
{
	int a=10,b=20;/*a,b-stack*/
	printf("a=%d,b=%d\n",a,b);
	printf("%d\n",fun(a,b));
	d=20;
	printf("d=%d\n",d);
}
