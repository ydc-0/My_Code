

#pragma pack(2)
class BU
{
	int number;
	union UBffer
	{
		char buffer[13];
		int number;
	}ubuf;
	void foo() {}
	typedef char*(*f)(void*);
	//enum { hdd, ssd, blueray }disk;
}bu;

int main()
{
	int i;
	i = sizeof(int );
	i;
	int b = i;
	return 0;
	
}