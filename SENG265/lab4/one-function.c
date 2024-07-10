#include <stdio.h>

int main()
{
    int a;
    int b;
    int *pp;

    a = 10;
    b = 20;

    printf("%d %d\n", a, b); 	//"10 20\n"

    pp = &a;	//pp is pointer for a
    *pp = 333;	//now a = 333

    printf("%d %d\n", a, b);	//"333 20\n"

    pp = &b;	//pp no longer affects a, only b
    a = 444;
    b = 555;

    printf("%d %d\n", a, b);	//"444 555\n"
    printf("%d\n", *pp);	//"555/n"
    printf("%p\n", (void *)pp);
}

/*will print
"10 20
333 20
444 555
555
"*/
