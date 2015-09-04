#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

void test1()
{
    qh::string str1;
    assert(str1 == "\0");

    qh::string str2("abc");
    assert(str2 == "abc");

    qh::string str3("abc", 6);
    assert(str3 == "abc");
    assert(str3.size() == 6);

    qh::string str4(str2);
    assert(str4 == str2);

    qh::string str5 = "abc";
    assert(str5 == "abc");
    
    assert(str5.size() == 3);
}

int main(int argc, char* argv[])
{
    test1();
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

