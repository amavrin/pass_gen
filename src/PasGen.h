#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


// максимальная длина пароля
#define MAXPLEN 255
// максимальная длина словаря
#define MAXDLEN 256

class PasGen {

int paslen;
int dictlen;

char dict[MAXDLEN] = {0};
char pass[MAXPLEN] = {0};

public:

PasGen(int len = 0){
	// необходимо задать длину пароля > 0
	assert(len > 0);
	// ... и меньше, чем MAXPLEN
	assert(len < MAXPLEN);

	paslen = len;

	// позиция в массиве dict;
	int dp = 0;

	// заполнение словаря символов
	for ( int c = 'A'; c <= 'Z'; c++) {
		dict[dp++] = c;
	}
	for ( int c = 'a'; c <= 'z'; c++) {
		dict[dp++] = c;
	}
	for ( int c = '0'; c <= '9'; c++) {
		dict[dp++] = c;
	}
	for ( int c = '!'; c <= '\''; c++) {
		dict[dp++] = c;
	}

	// по окончании инициализации позиция в словаре соответствует длине словаря
	dictlen = dp;

	// инициализация генератора случайных чисел
	struct timeval time;
	gettimeofday(&time,NULL);
	srand((time.tv_sec * 1000) + time.tv_usec);
}

char get_char() {
	int r = rand() % dictlen;
	return (char)dict[r];
}

char *gen_pass() {
	// берём нужное количество символов
	int pc = 0;
	for (pc = 0; pc < paslen; pc++) {
		pass[pc] = get_char();
	}
	// терминируем строку
	pc = 0;

	return pass;
}

int get_dlen() {
	return dictlen;
}

int set_plen(int newlen) {
	paslen = newlen;
}

};
