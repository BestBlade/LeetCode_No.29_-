/*--------------------------------------------------------------------------------------------------|
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。		|
																									|
返回被除数 dividend 除以除数 divisor 得到的商。														|
																									|
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2	|
																									|
 																									|
																									|
示例 1:																								|
																									|
输入: dividend = 10, divisor = 3																	|
输出: 3																								|
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3													|
示例 2:																								|
																									|
输入: dividend = 7, divisor = -3																	|
输出: -2																							|
解释: 7/-3 = truncate(-2.33333..) = -2																|
 																									|
																									|
提示：																								|
																									|
被除数和除数均为 32 位有符号整数。																	|
除数不为 0。																						|
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则	|
返回 231 − 1。																						|
																									|
来源：力扣（LeetCode）																				|
链接：https://leetcode-cn.com/problems/divide-two-integers											|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。								|
---------------------------------------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6 MB, 在所有 C++ 提交中击败了43.42%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int divide(int dividend, int divisor)
{
    //特殊处理
    if (divisor == -1)
    {
        if (dividend == INT_MIN)
            return INT_MAX;
        else
            return 0 - dividend;
    }
    if (dividend == 0)
    {
        return 0;
    }
       
    if (divisor == 1)
    {
        return dividend;
    }

    //转为负数
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    dividend = dividend > 0 ? 0 - dividend : dividend;
    divisor = divisor > 0 ? 0 - divisor : divisor;

    //如果被除数不够除就直接退出
    if (dividend > divisor)
    {
        return 0;
    }

    int result = 0;
    while (dividend < 0)
    {
        //如果被除数不够除就直接退出
        if (dividend > divisor)
        {
            break;
        }

        //开始计算商
        int divisor_pow_current = divisor;
        int count = -1;
        while (true)
        {
            //防止除数翻倍后越界
            if (INT_MIN - divisor_pow_current > divisor_pow_current)
            {
                break;
            }

            //防止除数翻倍后大于被除数
            if (divisor_pow_current + divisor_pow_current < dividend)
            {
                break;
            }

            count += count;
            //记得除数翻倍
            divisor_pow_current += divisor_pow_current;
        }
        dividend -= divisor_pow_current;
        result += count;
    }
    return sign == 1 ? 0 - result : result;
}

int main()
{
	int dividend = INT_MIN+1;
	int divisor = -1000000;
	//int result = divide(dividend,divisor);

	//cout << result << endl;

}