//--------------------------------------------------
// 2026 1학기 STL 월56 화78 6월 16일 (15주 1일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------
// universal reference - range for 에서 range factory를 이용할 때 사용
// 
// concept
// type traits
// 
// C++ Constrained Algothm ( Range + Concept )
//--------------------------------------------------
#include <iostream>
#include <vector>
#include <ranges>
#include <print>
#include "ZString.h"
#include "save.h"

using namespace std;

extern bool 관찰;

template <class T>
concept 숫자만 = is_integral_v<T> || is_floating_point_v<T>;

template<숫자만 T>
T add(const T& a, const T& b)
{
	return a + b;
}

class Dog {
public:
	Dog() = default;
	Dog(int n) : n(n) {};

	Dog operator+(const Dog& rhs) const {
		return n + rhs.n;
	}

private:
	int n;

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		return os << dog.n;
	}
};

//----------
int main()
//----------
{
	save("메인.cpp");

	// [문제] add 함수를 작성하라.
	cout << add(1, 2) << endl;
	cout << add(1.2, 3.4) << endl;
	// concept - 컴파일 타임에 조건을 판단할 수 있음.

	// [질문] 내가 만든 class Dog가 내가 만든 concept 숫자만을 만족하도록 하고 싶다.
	// cout << add(Dog{ 1 }, Dog{ 2 }) << endl;	// 3이라고 출력하라.
}