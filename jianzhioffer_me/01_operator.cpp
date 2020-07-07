//#include<iostream>
#include<cstring>
#include<cstdio>

//using namespace std;

class CMyString
{
	public:
		CMyString(char* pData = nullptr);
		CMyString(const CMyString& str);
		~CMyString(void);
		CMyString& operator=(const CMyString&);
		void Print();
	private:
		char* m_pData;
};

CMyString::CMyString(char *pData)
{
	if(pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len+1];
		strcpy(m_pData,pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len+1];
	strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
	m_pData = nullptr;
}
/*
CMyString& CMyString::operator=(const CMyString& str)
{
	if(this == &str) 
		return *this;

	delete []m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData)+1];
	strcpy(m_pData,str.m_pData);

	return *this;
}*/

CMyString& CMyString::operator=(const CMyString &str)
{
	if(this!=&str)
	{
		CMyString strTemp(str);

		char* Temp= strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = Temp;
	}
	return *this;
}

void CMyString::Print()
{
	printf("%s",m_pData);
}

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello Moto";
	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The excepted result is: %s.\n",text);
	printf("The actual result is:");
	str2.Print();
	printf("\n");
}

void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello Nokia";
	CMyString str1(text);
	str1 = str1;

	printf("The excepted result is :%s\n",text);
	printf("The actual result is :");
	str1.Print();
	printf("\n");
}

void Test3()
{
	printf("Test3 begins:\n");
	char* text = "Hello Apple";

	CMyString str1(text);
	CMyString str2,str3;
	str3 = str2 = str1;

	printf("The excepted result is : %s.\n",text);
	printf("The actual result is :");

	str2.Print();
	printf("\n");
	str3.Print();
	printf("\n");
}

int main()
{
	Test1();
	Test2();
	Test3();
}
