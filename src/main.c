#include "OJ.h"
#include "common_dataStruct.h"
#include "list.h"
#include "queue.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"
#include "time.h"

#define ISNUM(a) (a>='0' && a<='9'?1:0)

void clearCharry(char *str, int len)
{
    for(int i = 0;i < len;i++) {
        str[i] = '\0';
    }
}

int calNum(char* str)
{
    char des[100] = "\0";
    int cont = 0;
    int sum = 0;
    int tmp;
    int isAdd = 1;

    while(*(str+cont) != '\0') {
        if (ISNUM(*(str+cont))) {
            printf("isNum:%c \n", *(str+cont));
            strncat_s(des, 100, str+cont, 1);
            cont++;
            continue;
        }
        tmp = str2Num(des);
        clearCharry(des,100);

        if (isAdd == 1) {
            sum = sum + tmp;
        } else if (isAdd == 2) {
            sum = sum - tmp;
        }
        
        if(*(str+cont) == '+') {
            isAdd = 1;
            cont++;
        } else if (*(str+cont) == '-') {
            isAdd = 2;
            cont++;
        } else {
            cont++;
        }
    }

    tmp = str2Num(des);
    if (isAdd == 1) {
        sum = sum + tmp;
    } else if (isAdd == 2) {
        sum = sum - tmp;
    }

    printf("calNum:%d \n", sum);
    return sum;

}
, 
int main()
{
    char str[100] = "0";
    int num = 0;

    gets(str);

    printf("before calNum:%s\n", str);
    num = calNum(str);
    printf("the num:%d\n", num);
}
