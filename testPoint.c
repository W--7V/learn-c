#include <stdio.h>
#include <string.h>

int main(){
    // testPoint();

    char *s = "abcde";
    long *n = 10;
    printf("main pss %p ppn %p\n", &s, &n);
    printf("main ps %p pn %p\n", s, n);
    test2Point(&s, &n);
    // testPoint(s, n);
    printf("main string %s  %p\n", s, s);
    printf("main n %d  %p\n", n, n);
}

void testPoint(char *buf, int *n){
    // *buf = "buf";
    printf("testPoint ps %p\n", buf);
    printf("testPoint p %p\n", n);

    // *n = 15;
    // printf("testPoint string %s\n",*buf);

    // printf("string size %d", strlen(buf));
}

void test2Point(char **buf, int **n){
    printf("test2Point pss %p pnn %p\n", buf, n);
    printf("test2Point ps %p pn %p\n", *buf, *n);
    *buf = "abcdef";
    *n = 20;


    printf("test2Point string %s\n",*buf);

    // printf("string size %d", strlen(buf));
}
