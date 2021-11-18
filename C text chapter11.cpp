#include<stdio.h>
#define _1110

#ifdef _1101
int main(void) {
	const char* p = "123";
	printf("p = \"%s\"\n", p);

	p = "456" + 1;
	printf("p = \"%s\"", p);

	return 0;
}
/*
p[0]の記憶場所から順に4, 5, 6を代入したが、pはp[1]からを指すようになったため、
p[0]～p[2]までを占有しているpを表示させるとp[0]は空でp[1],p[2]が表示された。
 */
#endif

#ifdef _1102
int main(void) {
	char a[][5] = { "LISP","C","Ada" };
	const char* p[] = { "PAUL","X","MAC" };
	int num = sizeof(a) / 5;
	for (int i = 0; i < num; i++) {
		printf("a[%d] = \"%s\"\n", i, a[i]);
	}
	for (int i = 0; i < num; i++) {
		printf("a[%d] = \"%s\"\n", i, p[i]);
	}

	return 0;
}
#endif

#ifdef _1103

char* str_copy(char* d, const char* s) {
	char* t = d;
	while (*d++ = *s++)
		;
	return t;
}
int main(void) {
	char str[128] = "ABC";
	char tmp[128];

	printf("str = \"%s\"\n", str);

	printf("コピーするのは : ");
	scanf_s("%s", tmp,sizeof(tmp));

	puts("コピーしました。");
	printf("str = \"%s\"", str_copy(str, tmp));

	return 0;
}
#endif

#ifdef _1104
void put_string(const char* s) {
	printf("%s\n", s);
}

int main(void) {
	char str[] = "Luri Tear";
	
	put_string(str);

	return 0;
}
#endif

#ifdef _1105
int str_chnum(const char* s, int c) {
	int n = 0;
	while (*s) {
		if (*s++ == c) n++;
	}
	return n;
}

int main(void) {
	char str[128];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	printf("文字列に含まれる\'c\'は%d個です。", str_chnum(str,'c'));

	return 0;
}
#endif

#ifdef _1106
char* str_chr(const char* s, int c) {
	do {
		if (*s == c) return (char*)s;
	} while (*s++);

	return NULL;
}

int main(void) {
	char str[128];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	printf("%s\n", str_chr(str, 'c'));


	return 0;
}
#endif

#ifdef _1107
#include<ctype.h>
void set_toupper(char* s) {
	while (*s) {
		*s = toupper(*s);
		*s += 1;
	}
}void set_tolower(char* s) {
	while (*s) {
		*s = tolower(*s);
		*s += 1;
	}
}
int main(void) {
	char str[64];
	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	set_toupper(str);
	printf("大文字 : %s\n", str);
	
	set_tolower(str);
	printf("小文字 : %s", str);

	return 0;
}
#endif

#ifdef _1108
#include<ctype.h>
void del_digit(char* str) {
	int i = 0;
	while (*str) {
		if (isdigit(*str)) {
			i++;
		}
		else {
			*(str - i) = *str;
		}
		*str++;
	}
	*(str - i) = '\0';
}

int main(void) {
	char s[64];
	printf("文字列を入力してください : ");
	scanf_s("%s", s, sizeof(s));

	del_digit(s);
	printf("数字文字を削除しました : %s", s);

	return 0;
}
#endif

#ifdef _1109
#include<string.h>
int main(void) {
	char str[128] = "\0";
	char a[128];
	char b[128] = "ABC";

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));
	putchar('\n');

	printf("入力された文字列は%d文字です。\n", strlen(str));
	
	strcpy_s(a, str);
	printf("文字列aにコピー : % s\n", a);

	strncpy_s(b, a, strlen(a));
	printf("文字列bへ文字列aの文字数分コピー : %s\n", b);

	if (strcmp(a, str) == 0) {
		puts("文字列aとstrは一致。");
	}
	else {
		puts("文字列aとstrは不一致。");
	}

	if (strncmp(b, a, strlen(str)) == 0) {
		puts("「b」と「a」の文字数分の文字列は一致。");
	}
	else {
		puts("「b」と「a」の文字数分の文字列は不一致。");
	}
		
	return 0;
}
#endif

#ifdef _1110
#include<stdlib.h>
/*整数部分桁数のカウント*/
int numInteger(char* s) {
	int cnt = 0;
	while (*s++) {
		cnt++;
		if (*s == '.') break;
	}
	return cnt;
}
/*小数部分桁数のカウント*/
int numDecimal(char* s) {
	int i = numInteger(s);
	int cnt = 0;
	while (*s++) {
		cnt++;
	}
	cnt -= (i + 1);
	return cnt;
}

/*10の+n乗の処理*/
int Power10(int n) {
	int X = 1;
	for (n; n > 1; n--) {
		X *= 10;
	}
	return X;
}
/*10の-n乗の処理*/
float Power01(int n) {
	float X = 1;
	for (int i = 0; i <= n; i++) {
		X /= 10;
	}
	return X;
}

/*数字文字の判定*/
int number(const char c) {
	int n = c - '0';
	return n;
}
/*atoi*/
int strtoi(const char* nptr) {
	int num = 0;
	int i = numInteger((char*)nptr);

	while (*nptr) {
		if (*nptr == '.') break;
		num += Power10(i) * number(*nptr);
		i--;
		(char*)nptr++;
	}
	return num;
}
/*atol*/
long strtol(const char* nptr) {
	long num = 0;
	int i = numInteger((char*)nptr);
	while (*nptr) {
		if (*nptr == '.') break;
		num += Power10(i) * number(*nptr);
		i--;
		(char*)nptr++;
	}
	return num;
}
/*atof*/
double strtof(const char* nptr) {
	double num = 0;
	int i = numInteger((char*)nptr);
	int d = numDecimal((char*)nptr);
	int sw = 0;
	int cnt = 0;

	while (*nptr) {
		if (*nptr == '.') sw = 1;
		else if (sw == 0) {
			num += (double)Power10(i) * number(*nptr);
			i--;
		}
		else if (sw == 1) {
			num += (double)Power01(cnt) * number(*nptr);
			cnt++;
		}
		(char*)nptr++;
	}
	return num;
}

int main(void) {
	char strI[32] = "123.456";
	char strL[32] = "123.456";
	char strD[32] = "123.456789";
	int X;
	long Y;
	double Z;

	X = strtoi(strI);
	printf("[int型]X = %d(atoi = %d)\n", X, atoi(strI));
	Y = strtol(strL);
	printf("[long型]Y = %ld(atol = %ld)\n", Y, atol(strL));
	Z = strtof(strD);
	printf("[double型]Z = %lf(atof = %lf)\n", Z, atof(strD));

	return 0;
}
#endif


