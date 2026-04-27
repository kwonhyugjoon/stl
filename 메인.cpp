//--------------------------------------------------
// 2026 1학기 STL 월56 화78 4월 27일 (8주 2일)
//--------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//--------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<int> v{ 1, 2, 3, 4, 5 };

	// [문제] v에서 3을 제거하라. v.size() == 4, 원소{1, 2, 4, 5}, v.capacity() == 5
	// 원소제거는 std::remove()를 이용하면 된다.

	std::remove(v.begin(), v.end(), 3); // {1,2, 4, 5, 5}

}