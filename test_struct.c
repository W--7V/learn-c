#include <stdio.h>


struct my_struct
{
    int n:8;
};


int main() {

    int *p = {1, 2, 3, 4, 5};
    int a[5] = {1, 2, 3, 4, 5};

    int n = 12;
    int *pn;
    pn = & n;
    // my_struct ms;


    printf("sizeof(p) %d\n",sizeof(p));
    printf("sizeof(a) %d\n",sizeof(a[0]));
    printf("p %p\n",p);
    printf("a %d\n",a[0]);
    printf("pn %d\n",*pn);

 
    return 0;


}