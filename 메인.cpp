//--------------------------------------------------
// 2026 1학기 STL 월56 화78 4월 14일 (7주 1일)
// 중간고사 4월 21일 (8주 1일)
//--------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects. STL 컨테이너는 다른 객체를 저장하는 객체이다.
//--------------------------------------------------
#include <iostream>
#include <fstream>
#include "save.h"
#include "ZString.h"

extern bool 관찰;

//--------
int main()
//--------
{
	// [문제] "메인.cpp"에 있는 모든 단어를 ZString 객체로 읽어와라.
	// 
	// 다음 문장이 문제없이 실행되도록 하자.

	std::ifstream in{ "메인.cpp" };

	if (not in) {
		std::cout << "파일 없음" << std::endl;
		return 1;
	}

	ZString s;
	while (in >> s) {
		std::cout << s << std::endl;
	}

	save("메인.cpp");
	
}