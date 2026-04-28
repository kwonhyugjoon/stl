//--------------------------------------------------
// 2026 1학기 STL 월56 화78 4월 28일 (9주 1일)
//--------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//--------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>			// insert 예시를 위해 추가
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	std::list<ZString> v{ "1", "22", "4444", "55555"};

	// [문제] "22" 다음에 "333"을 추가하라.
	관찰 = true;
	v.emplace(++++v.begin(), "333");
	관찰 = false;
	for(const ZString& zs : v)
		std::cout << zs << std::endl;
}