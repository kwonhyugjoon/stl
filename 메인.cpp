//--------------------------------------------------
// 2026 1학기 STL 월56 화78 6월 02일 (13주 1일)
// 6/22 시험(15/2) - 제일 마지막 시험
//--------------------------------------------------
// 
//--------------------------------------------------
#include <iostream>
#include <map>
#include <random>
#include <print>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 0, 10'000 };
std::normal_distribution nd{ 0.0, 0.09 };

//--------
int main()
//--------
{
	save("메인.cpp");

	// map - 어디에 쓸 수 있나
	// 유니폼 분포는 유니폼한가?
	// 노멀분포를 화면에 출력

	std::map<size_t, size_t> 노멀;
	for (int i = 0; i < 100'000'000; ++i) {
		double num = nd(dre);
		num = num * 5000 + 5000;
		if (num < 0)
			num = 0;
		if (10000 < num)
			num = 10000;

		++노멀[num / 200];
	}

	for (auto [구간, 개수] : 노멀) {
		std::println("[{:2}] - {}", 구간, 개수);
	}
}