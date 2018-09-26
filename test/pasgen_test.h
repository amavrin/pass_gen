#include <iostream>
#include <string.h>

#include "../src/PasGen.h"

class PasgenTest : public CxxTest::TestSuite {

public:

// проверим, что символы берутся из нужных диапазонов
void testCanGetRandomChar() {
	PasGen pass(1);
	std::cout << std::endl;
	for (int i = 0; i < 1024; i++) {
		int c = pass.get_char();
		TS_ASSERT(
			( c >= 'A' && c <= 'Z') ||
			( c >= 'a' && c <= 'z') ||
			( c >= '0' && c <= '9') ||
			( c >= '!' && c <= '\'' )
		);
		std::cout << (char)c;
	}
	std::cout << std::endl;
}

// проверим, что пароль генерируется нужной длины
void testCanGetSomePassAndLenIsCorrect() {
	int plen = 8;
	PasGen pass(plen);
	char buf[BUFSIZ] = {0};
	strcpy(buf, pass.gen_pass());
	std::cout << std::endl << buf << std::endl;
	TS_ASSERT_EQUALS(strlen(buf), plen);
}

// проверим, что количество символов в словаре равен ожидаемому
void testCorrentDictLen() {
	PasGen pass(1);
	TS_ASSERT_EQUALS(pass.get_dlen(), 26+26+10+7);
}

// проверим, что мы можем менять длину пароля
void testCanSetPassLen() {
	PasGen pass(1);
	int plen = 8;
	pass.set_plen(plen);
	char buf[BUFSIZ] = {0};
	strcpy(buf, pass.gen_pass());
	std::cout << std::endl << buf << std::endl;
	TS_ASSERT_EQUALS(strlen(buf), plen);
}

// очень грубая оценка, что символы генерируются случайным образом
void testRandomIsQuiteRandom() {
	PasGen pass(1);
	int a_count = 0;
	int large = 1000000;
	for (int i = 0; i < large; i++) {
		pass.get_char() == 'a' ? a_count++ : a_count;
	}

	int a_prob_count = large / pass.get_dlen();

	TS_ASSERT_LESS_THAN( a_count, a_prob_count + a_count/3);
	TS_ASSERT_LESS_THAN( a_prob_count - a_count/3, a_count);
}

};
