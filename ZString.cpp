//--------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 4.13
//--------------------------------------------------
#include <print>
#include <string>
#include <algorithm>		// equal 2026. 4. 28
#include "ZString.h"

size_t ZString::gid{};				// 외부에서 초기화
bool 관찰{ false };

ZString::ZString()
	: id{ ++gid }
{
	if (관찰) special("생성");
};

ZString::~ZString()
{
	if (관찰) special("소멸");
};

ZString::ZString(const char* s) 
	: id{ ++gid }
{
	len = strlen(s);						// 글자 수 세서 len에 저장
	p = std::make_unique<char[]>(len);		// 글자 수 만큼 unique_ptr로 char 배열을 관리
	memcpy(p.get(), s, len);				// s에서 len 글자만큼 p로 복사. 제일 밑바닥에 있는 메모리 카피 함수. 초고속 카피 가능

	// << -> 고급출력. 인자가 char*일 때 p.get()주소로부터 시작해서 null문자를 만날 때 까지 문자열로 출력한다.
	// 그래서 주소를 보고싶으면 (void*)로 캐스팅해서 출력해야 한다.

	if (관찰) special("생성(+)");
}

// 복사생성과 복사할당연산자
ZString::ZString(const ZString& other)
	: id { ++gid }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);		// other.p.get()주소로부터 시작해서 len 글자만큼 p로 복사

	if (관찰) special("복사생성");
}

ZString& ZString::operator=(const ZString& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);
	if (관찰) special("복사할당");
	return *this;
}

// 이동 - C++11부터 지원되는 move semantics
// 2026. 04. 20 move에서 예외를 던지지 않는다.
//ZString::ZString(ZString&& other) noexcept
//	: id{ ++gid }
//{
//	len = other.len;
//	p.reset(other.p.release());	// other의 p가 관리하는 메모리를 가져옴 - other는 자동으로 nullptr이 됨
//
//	other.len = 0;
//	// 자기 자원이 이동된 other는 xvalues가 되고 이것을 사용하면 undefined behavior
//	if (관찰)
//		special("이동생성");
//}
//
//ZString& ZString::operator=(ZString&& other) noexcept
//{
//	if (this == &other)
//		return *this;
//
//	len = other.len;
//	// 잘 한 건가? 내 메모리 반환했나?
//	p.reset(other.p.release());
//	other.len = 0;
//
//	if (관찰)
//		special("이동할당");
//
//	return *this;
//}

// 2026. 4. 28
bool ZString::operator==(const ZString& rhs) const
{
	// 동등성(equality)과 상등성(equivalence)의 차이
	// id, len, p가 있는데 ==> 내가 관리하는 글자가 같으면 같은거다.
	if (len != rhs.len)
		return false;

	return std::equal(p.get(), p.get() + len, rhs.p.get());			// 아래코드보다 STL에 적합한 코드

	/*for (int i = 0; i < len; ++i){
		if (p[i] != rhs.p[i])
			return false;
	}
	return true;*/
}

// 2026. 6. 1
// set의 기본정렬 연산자 <
// 사전식 정렬되도록 코딩
bool ZString::operator<(const ZString& rhs) const
{
	return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
}

// 2026. 05. 12 - 반복자 인터페이스
ZString_Iterator ZString::begin() const
{
	return p.get();
}

ZString_Iterator ZString::end() const
{
	return p.get() + len;
}

// 2026. 05. 18 - 역방향 추가
// 2026. 05. 19 - 역방향반복자는 반드시 class로 코딩해야 합니다.
ZString_Iterator ZString::rbegin() const
{
	return p.get() + len;
}

ZString_Iterator ZString::rend() const
{
	return p.get();
}

size_t ZString::getLen() const
{
	return len;
}

// STL 컨테이너가 되려면 다음 함수정도는 제공해야 - 2026. 4. 20
size_t ZString::size() const
{
	return len;
}

char* ZString::data() const		// 2026. 05. 11
{
	return p.get();
}

void ZString::special(std::string 동작) const
{
	// 글자수가 10개 이상이라도 10개 까지만 출력
	int num = 10;
	if (len < 10)
		num = len;
	std::string 글자{};
	for (int i = 0; i < num; ++i)
		글자 += p[i];
	std::println("[{:7}] {:8} - 객체:{:#016X}, 글자:{:#016X}, 개수:{:<6} 내용:{}",
		id, 동작, (long long)this, (long long)p.get(), len, 글자);
}

void ZString::show() const		// 2026. 4. 20
{
	special("show");
}

std::ostream& operator<<(std::ostream& os, const ZString& zs) 
{
	for (size_t i = 0; i < zs.len; ++i)
		os << zs.p[i];
	return os;
}

std::istream& operator>>(std::istream& is, ZString& zs)
{
	// 그림 설명에서 시작

	std::string s;
	is >> s;
	zs.len = s.size();
	zs.p.reset();
	zs.p = std::make_unique<char[]>(s.size());
	memcpy(zs.p.get(), s.data(), zs.len);

	return is;
}