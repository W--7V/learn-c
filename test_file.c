#include <stdio.h>
#include<time.h>
// #include <sys/sendfile.h>

int main() {
    FILE *fp_passwd = fopen("c_passwd.txt", "w+");
    FILE *rfp_passwd = fopen("r_passwd.txt", "w+");
    continus_write_file(fp_passwd);
    random_write_file(rfp_passwd);
    fclose(fp_passwd);
    fclose(rfp_passwd);
}

void continus_read_file(FILE *fp_passwd){
    int ch;
    while ((ch = fgetc(fp_passwd)) != EOF)   {
        printf("%c", ch);
    }
    printf("\n");
}

void continus_write_file(FILE *fp_passwd){
    clock_t start, end;
    start = clock();
    char buf[] = "this is a test for fputcc";
    for(int j=0;j<100000;j++){
        for (int i = 0; i < strlen(buf); i++)
        {
            //往文件fp写入字符buf[i]
            int ch = fputc(buf[i], fp_passwd);
            // printf("ch = %c\n", ch);
        }
    }
    end = clock();
    printf("continus_write_file time : %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
}

void random_write_file(FILE *fp_passwd){
    clock_t start, end;
    start = clock();
    char buf[] = "this is a test for fwrite";
    for(int j=0;j<100000;j++)
    {
        //往文件fp写入字符buf[i]
        fwrite(buf, sizeof(buf), 1, fp_passwd);
    }
    end = clock();
    printf("random_write_file time : %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
}