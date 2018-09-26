#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


// максимальная длина пароля
#define MAXPLEN 255
// максимальная длина словаря символов для генерации паролей
#define MAXDLEN 256

class PasGen {

// длина пароля, который будет возваращаться методом gen_pass()
int paslen;
// количество символов, из которых будут составляться пароли
int dictlen;

// тут храним массив символов
char dict[MAXDLEN] = {0};
// тут будем хранить генерируемый пароль
char pass[MAXPLEN] = {0};

public:

PasGen(int len = 0){
	// необходимо задать длину пароля > 0
	assert(len > 0);
	// ... и меньше, чем MAXPLEN
	assert(len < MAXPLEN);

	paslen = len;

	// позиция в массиве dict
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

	// инициализация генератора случайных чисел текущим временем, с разрешением до миллисекунд
	struct timeval time;
	gettimeofday(&time,NULL);
	srand((time.tv_sec * 1000) + time.tv_usec);
}

// возвращаем случайный символ из словаря символов
char get_char() {
	int r = rand() % dictlen;
	return (char)dict[r];
}

// генерируем пароль длины paslen
char *gen_pass() {
	int pc = 0;
	// берём нужное количество символов
	for (pc = 0; pc < paslen; pc++) {
		pass[pc] = get_char();
	}
	// терминируем строку
	pc = 0;

	return pass;
}

// сообщаем количество символов из словаря символов
int get_dlen() {
	return dictlen;
}

// можем установить новую длину пароля
int set_plen(int newlen) {
	paslen = newlen;
}

};
