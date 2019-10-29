/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/
/******************************************************************************
 * Copyright (c) JingMingGroup All rights reserved.
-------------------------------------------------------------------------------
  File name     : reverseList.c
  Author        : iSpringTime
  Create        : 2019.10.23
  Description   : reverse list (demo)
******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
 
void print_num(int n, int m, vector<int>& num)
{
    //递归出口
    if (m<= 0 || n <= 0)return;
    //找到合适的解法
    if (m == n)
    {
        for (int i = 0; i < num.size(); i++)
        {
            cout << num[i] << "\t";
        }
        cout << n;
        cout << endl;
        return;
    }
    num.push_back(n);
    print_num(n-1, m - n, num);
    num.pop_back();
    print_num(n-1,m,num);
}
 
int main()
{
    vector<int> data;
    print_num(6, 8, data);
    system("pause");
    return 0;
}
