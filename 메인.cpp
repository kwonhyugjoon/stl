//--------------------------------------------------
// 2026 1학기 STL 월56 화78 4월 04일 (9주 2일)
//--------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T> - 아무대서나 원소 추가/삭제 0(1)
//--------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	//[문제] 파일에 있는 단어를 list<ZString>에 저장하라.
	//단어를 사전식 오름차순으로 정렬하라.
	std::ifstream in("2026년 1학기 STL 월56 화78.txt");
	if (not in) {
		std::cout << "파일을 열 수 없습니다." << std::endl;
		return 20260504;
	}

	std::list<ZString> words{ std::istream_iterator<ZString>{in}, {} };
	words.sort([](const ZString& a, const ZString& b) {
		// 다음시간에 -> 정렬시간비교
		lexicographical_compare(a,)
		});
}