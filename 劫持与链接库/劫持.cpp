

#include"detours.h"  //ʹ��lib�ķ���
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
	DetourRestoreAfterWith();//�ָ�ԭ��״̬
	static int (* poldsystem)(char const*) = system;
	DetourTransactionBegin();//���ؿ�ʼ
	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
										   //�������������ε���DetourAttach������HOOK�������
	DetourAttach((void **)&poldsystem, newsystem);//ʵ�ֺ�������
	DetourTransactionCommit();//������Ч
}

int main()
{

	system("calc");
	Hook();

	system("calc");

	return 0;
}