#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假如这里有 n 个台阶，每次你可以跨 1 个台阶或者 2 个台阶，请问走这 n 个台阶有多少种走法？
// 使用递归函数实现
int one_two_step(int n)
{
    if (n < 1)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return one_two_step(n - 1) + one_two_step(n - 2);
}
