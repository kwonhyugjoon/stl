//---------------------------------------------------------------
// 한 학기 강의를 저장하기 위한 함수
//
// 2026. 3. 9
//---------------------------------------------------------------

#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include "save.h"

void save(const std::string& fname)
{
	std::ifstream in{ fname };
	if (not in) {
		std::cout << fname << "- 열 수 없습니다" << '\n';
		exit(2026030);
	}

	std::cout << "\"" << fname << "\"를 저장합니다" << '\n';

	std::ofstream out{ "2026년 1학기 STL 월56 화78.txt", std::ios::app };

	auto now = std::chrono::system_clock::now();

	using namespace std::chrono_literals;

	out << '\n' << '\n';
	out << "=========================================" << '\n';
	out << "저장한 시간 - " << now + 9h << '\n';
	out << "=========================================" << '\n';
	out << '\n';

	std::copy(std::istreambuf_iterator <char>{in}, {},
		std::ostream_iterator<char>{out});
}
