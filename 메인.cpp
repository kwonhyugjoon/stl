//--------------------------------------------------
// 2026 1학기 STL 월56 화78 5월 26일 (12주 1일)
// 6/22 시험(15/2)
//--------------------------------------------------
// 반복자를 이용한 C++ 프로그램(uniform manner) - STL 알고리즘 함수
//--------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

template<class 반복자, class 출력반복자>
void my_copy(반복자 b, 반복자 e, 출력반복자 o)
{
	while (b != e) {
		*o = *b;
		++b;
		++o;
	}
}

//--------
int main()
//--------
{
	save("메인.cpp");

	ZString zs{ "sphinx of black quartz 3 judge my 6 vow" };
	
	// 코드 설명은 다음주에
	my_copy(zs.begin(), zs.end(), std::ostream_iterator<ZString::value_type>{std::cout, " ### "});

	std::cout << zs << std::endl;
}