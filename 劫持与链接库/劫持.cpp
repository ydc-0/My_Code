

#include"detours.h"  //使用lib的方法
#pragma comment(lib,"detours.lib")
#include"detver.h"


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int __cdecl newsystem(
	_In_opt_z_ char const* _Command
)
{
	MessageBox(0, L"1111", L"2222222", 0);
	return 0;
}

void Hook()
{
	DetourRestoreAfterWith();//恢复原来状态
	static int (* poldsystem)(char const*) = system;
	DetourTransactionBegin();//拦截开始
	DetourUpdateThread(GetCurrentThread());//刷新当前线程
										   //这里可以连续多次调用DetourAttach，表明HOOK多个函数
	DetourAttach((void **)&poldsystem, newsystem);//实现函数拦截
	DetourTransactionCommit();//拦截生效
}

int main()
{

	system("calc");
	Hook();

	system("calc");

	return 0;
}