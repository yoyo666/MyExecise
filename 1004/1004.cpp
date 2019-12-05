﻿// 1004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
https://www.dotcpp.com/oj/problem1004.html
问题 1004: [递归]母牛的故事
时间限制: 1Sec 内存限制: 128MB
题目描述：
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
输入：
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。
输出：
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。
样例输入：
2
4
5
0
样例输出：
2
4
6

*/
/*
思路：动态规划，S[n]即为存储动态规划表的数组，因为单纯使用递归会超时
day1:1
day2:(1+1)=2
day3:(1+1+1)=3
day4:(1+1+1+1)=4
day5:(1+1+1+1+1)+1=6
day6:(1+1+1+1+1+1)+(1+1)+1=9
......
s(n) =s(n-1)+s(n-3),n>=4
*/
#include "pch.h"
#include <iostream>
using namespace std;

int NumOfCow(int n)
{
	int S[60] = { 0 };//记录每年的母牛数量
	S[0] = 0;
	S[1] = 1;
	S[2] = 2;
	S[3] = 3;
	
	if (n <= 0) return -1;
	if (n >= 4)
	{
		for (int i = 4; i <= n; i++)
		{
			S[i] = S[i - 1] + S[i - 3];
		}
	}
	int res = S[n];
	return res;
}


int main()
{
	int Year=1;

	scanf_s("%d", &Year);
	while (Year != 0)
	{
		printf("%d\n", NumOfCow(Year));
		scanf_s("%d", &Year);
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单