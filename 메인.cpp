//--------------------------------------------------
// 2026 1학기 STL 월56 화78 5월 12일 (10주 2일)
//--------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T> - 아무대서나 원소 추가/삭제 0(1)
// - deque<T> - vector와 list의 장점을 갖는 컨테이너
// - forward_list<T> - 아무리 잘 코딩해도 이보다 효율적인 코드는 불가능
//					   It is intended that forward_list have zero space or time overhead relative to a hand-written C-style singlely-linked list.
//--------------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	ZString zs{ "The quick brown fox jumps over the lazy dog" };
	std::sort( zs.data(), zs.data() + zs.size() );

	// [문제] 거꾸로 출력하세요.
	for(char c : zs )		// begin, end 구현으로 가능
		std::cout << c << "-";
	std::cout <<std::endl;
}