#include<stdio.h>
#include<windows.h>

void Hook()
{
	
}

int main()
{

	system("calc");
	Hook();

	system("calc");

	return 0;
}