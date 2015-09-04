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
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

