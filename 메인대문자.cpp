//--------------------------------------------------
// 2026 1학기 STL 월56 화78 3월 30일 (4주 2일)
//--------------------------------------------------
// 콜러블 타입 -> 실습 -> STL
//--------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

// [문제] "메인.CPP"의 소문자를 모두 대문자로 바꾼 "메인대문자.CPP"를 만들어라.
//TRANSFORM(뭐를, 뭐로, 어떻게);

//---------
INT MAIN()
//---------
{
	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		RETURN 20260330;
	}

	STD::OFSTREAM OUT{ "메인대문자.CPP" };

	//TRANSFORM( 메인시작, 메인끝, 메인대문자시작으로, 함수의시작번지 )
	TRANSFORM( STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, STD::OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[] (CHAR C) { 
			RETURN C = TOUPPER(C);
		} );

	SAVE("메인.CPP");

}
