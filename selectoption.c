#include "schedule.h"

static void all_search(t_sche *search)					// 모든 스케쥴을 출력하는 함수
{
	print_haeder();										// 헤더 먼저 출력
	while (search->next)								// 링크드리스트가 끝날때까지
	{
		print_schedule(search);							// 스케쥴 출력
		search = search->next;							// 다음 구조체로 이동
	}
	print_end_bar();									// 결과를 모두 출력 후 마지막에 출력
}

static void place_search(t_sche *search)				// 장소만 찾아서 출력
{
	char place[100];									// 장소를 입력받아 저장하는 배열
	int flag;											// flag 변수

	flag = 0;											// flag 초기화
	printf("Which place ? : ");							// 어느 장소인지 입력하는 문자열 출력
	scanf("%s", place);									// 입력받기
	while (search->next)								// 링크드리스트 전부 검색
	{
		if ((strcmp(place, search->location)) == 0)		// 입력 받은 값과 같으면
		{
			flag++;										// flag를 하나 증가
			if (flag == 1)								// flag가 1 일때만 헤더 출력
				print_haeder();
			print_schedule(search);						// 매치 된 결과 출력
		}
		search = search->next;							// 다음 링크드리스트로 이동
	}
	print_end_bar();									// 모든 결과 출력 후 마지막에 출력
}

static void month_search(t_sche *search)				// 월로 검색
{
	int month_input;									// 입력받을 월
	int flag;											// 플래그

	flag = 0;											// 플래그 초기화
	while (1)											// 반복
	{
		printf("Which month ? : ");						// 월 입력 문자
		scanf("%d", &month_input);						// 월 입력
		if (month_input >= 1 && month_input <= 12)		// 1 ~ 12 사이 입력 받으면 반복 종료
			break;
	}
	while (search->next)								// 모든 링크드리스트 검색
	{
		if (search->month == month_input)				// 입력받은 월과 같은 월이면
		{
			flag++;										// 플래그 1 증가
			if (flag == 1)								// 플래그가 1이면 헤더 출력
				print_haeder();
			print_schedule(search);						// 결과 출력
		}
		search = search->next;							// 다음 링크드 리스트로 이동
	}
	print_end_bar();									// 마지막에 출력
}

static void type_search(t_sche *search)					// 같은 타입의 스케쥴 검색
{
	char type[100];										// 스케쥴 입력
	int type_input;										// 입력받은 스케쥴을 정수로 변환
	int flag;											// 플래그
	extern char type_string[MAX_TYPE][20];				// 스케쥴 문자열 구조체

	flag = 0;											// 플래그 초기화
	type_input = 0;										// 입력받은 타입 초기화
	printf("Which type ? : ");							// 어떤 타입 스케쥴인지 입력
	scanf("%s", type);									// 입력 받아 배열에 저장
	while (type_string[type_input] != '\0')				// 0부터 7개의 타입 문자열 전부 검색
	{
		if ((strcmp(type, type_string[type_input])) == 0)		// 입력받은 값과 일치하는 값이 나오면
			break;												// 반복문 종료
		type_input++;											// 입력받은 타입 변수를 하나 증가시켜 다시 검색
		if (type_input == 7)									// 입력받은 값이 저장된 타입 문자열과 일치하는 것이 없으면 종료
		{
			printf("Input Right schedule type\n");				// 출력 후 종료
			return;
		}
	}

	while (search->next)										// 모든 링크드리스트 검색
	{
		if (search->type == type_input)							// 입력받은 타입값과 일치하는 스케쥴이 나오면
		{
			flag++;												// 플래그를 1 증가시킴
			if (flag == 1)										// 플래그가 1이면 헤더 출력
				print_haeder();
			print_schedule(search);								// 결과출력
		}
		search = search->next;									// 다음 리스트로 이동
	}
	print_end_bar();											// 마지막에 출력
}

void select_option(t_sche *worklist)							// 옵션을 선택하는 함수
{
	int num;													// 입력받을 옵션
	t_sche *search;												// 링크드 리스트 이동에 사용

	search = worklist;											// 이동에 사용할 구조체에 처음 시작값 저장
	while (1)													// 5번 선택 후 종료시까지 반복
	{
		print_messege();										// 옵션 선택 문자열 출력
		scanf("%d", &num);										// 옵션 입력받기
		if (num == 1)											// 1이면
			all_search(search);									// 모든 스케쥴 출력
		else if (num == 2)										// 2이면 월별 스케쥴 출력
			month_search(search);
		else if (num == 3)										// 3이면 장소별 스케쥴 출력
			place_search(search);
		else if (num == 4)										// 4이면 타입별 스케쥴 출력
			type_search(search);
		else if (num == 5)										// 5이면 종료
			break;
		else
			continue ;
	}
}
