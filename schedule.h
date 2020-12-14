#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFSIZE 32								// .dat 파일에서 한 번에 읽어올 문자의 갯수를 설정하는 변수
#define MAX_TYPE 7								// 전체 type 갯수 type_string 구조체에서 사용할 변수

typedef struct	s_sche							// 스케쥴 구조체
{
	char *work;									// 스케쥴 내용
	char *location;								// 스케쥴 장소
	int type;									// 스케쥴 타입
	int month;									// 월
	int day;									// 일
	struct s_sche *next;						// 링크드리스트 다음 구조체 주소값
}				t_sche;

//util.c
char	*bufjoin(char *str1, char *str2);		// 2개의 문자열을 붙이는 함수
char	*join_character(char *str, char a);		// 문자열에 1개의 캐릭터를 붙이는 함수
int		join_integer(int a, int b);				// 정수형 변수끼리 합치는 함수
void	del_memory(t_sche *lst, char *str);		// 동적할당 메모리 회수

//parsing.c
char	*readfile(void);						// .dat 파일을 읽어오는 함수
char	*parsing_string(t_sche *l_sche, char *schedule, int flag);	// .dat에서 schedule 문자열로 옮긴 것 중에 문자열 정보를 구조체에 저장
char	*parsing_integer(t_sche *l_sche, char *schedule, int flag);	// .dat에서 schedule 문자열로 옮긴 것 중에 정수형 정보를 구조체에 저장
t_sche	*parse(char *schedule);										// .dat에서 schedule 문자열로 옮긴 것을 스케쥴별로 쪼개서 링크드리스트로 만드는 함수

//linkedlist.c
void add_node(t_sche *target);					// 링크드 리스트의 다음 노드를 추가하는 함수

//print.c
void print_messege(void);						// 옵션 선택 메세지 출력
void print_haeder(void);						// 결과 출력시 맨 위 공백 출력
void print_schedule(t_sche *search);			// 결과 출력
void print_end_bar(void);						// 모든 결과 출력 후 바닥 부분 bar 출력

//select_option.c
void select_option(t_sche *worklist);			// 옵션 선택을 입력 받아서 탐색 및 결과 출력 함수를 호출하는 함수
