#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<time.h>
#include<unistd.h>
int test_sendfile(int s, int t);
int test_readwrite(int s, int t);

int main(){
    int source = open("c_passwd.txt", O_RDWR);
    int source1 = open("c_passwd.txt", O_RDWR);
    int target = open("target.txt", O_RDWR | O_CREAT);
    int target1 = open("target1.txt", O_RDWR | O_CREAT);
    test_sendfile(source, target);
    test_readwrite(source1, target1);
    close(source);
    close(source1);
    close(target);
    close(target1);
}

int test_sendfile(int s, int t){
    int res = 0;
    clock_t start, end;
    start = clock();
    res = sendfile(t, s, NULL, 2000000000);
    end = clock();
    printf("sendfile time : %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
    printf("sendfile res:%d\n", res);
    return res;
}

int test_readwrite(int s, int t){
    int res = 0, size = -1;
    clock_t start, end;
    char buf[1024 * 1024];
    start = clock();
    while (size != 0) {
        size = read(s, buf, 1024 * 1024);
        write(t, buf, size);
    }
    
    end = clock();
    printf("readwrite time : %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
    printf("readwrite res:%d\n", res);
    return res;
}