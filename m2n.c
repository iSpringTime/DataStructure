/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

// 只能引入基础的头文件，安全函数库的头文件已经引入.
// 已经集成安全函数库，请使用安全函数的接口.
// 通过标准输入流输入（安全函数scanf_s），通过标准输出流输出.

// 只能引入基础的头文件，安全函数库的头文件已经引入.
// 已经集成安全函数库，请使用安全函数的接口.
// 通过标准输入流输入（安全函数scanf_s），通过标准输出流输出.

double Calculate(double num, int n)
{
  double input = num;
  double output = 0;
  int tmp = 0;
  int cout = 0;

  if((num == 0) && (n == 0)) {
    return 1;
  }

  for (int i = 0;i < 10;i++) {
    cout++;
    input *= n;
    tmp = (int)input;
    output = output + tmp * pow(0.1, cout);
    input = input - tmp;
  }

  return output;
}

int main()
{
    
    // please define the C input here. For example: int n; scanf("%d",&n);
    
    // please finish the function body here.
    
    // please define the C output here. For example: printf("%d\n",a);
    
    double input;
    double output;
    int n;
    
    while(scanf("%lf %d", &input, &n) != EOF) {
      output = Calculate(input, n);

      if (output == 1) {
        continue;
      } else {
        printf("%.10f\n", output);
      }
    }

    return 0;
}


// int main()
// {
//     double m;
//     double i;
//     int tmp,n;
//     int count = 0;
//     int output[10] = {0};
//     while((scanf_s("%lf %d",&m,&n)) !=EOF)
//     {
//         if(m == 0 && n==0)
//         {
//             break;
//         }
//         count = 0;
//         while(count<10)
//         {
//             i = n*m;  //小数的N进制求法是将该数m乘以N之后，输出其整数，并将m的值赋值为相乘去整之后的值
//             m = i-(int)i;  //去掉整数部分！
//             output[count] = (int)i;
//             count++;   
//         }
//         printf("0.");
//         for(tmp=0; tmp<count; tmp++)
//         {
//             printf("%d",output[tmp]);
//         }
//        printf("\n");  //这个是不同的的用例输出需要换行
//     }
//     return 0;
// }


// 0.000001 2
// 0.000001 3

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
