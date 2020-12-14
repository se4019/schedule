#include "schedule.h"

char	*readfile(void)
{
	char buf[BUFFSIZE];											// 버퍼 사이즈 변수만큼 읽어들여서 저장할 배열
	int fd;														// 파일 디스크립터
	int ret;													// 리턴 값
	char *store;												// 임시 버퍼에 읽어들여온 값을 저장할 문자열
	int count;
	
	printf("Reading the data files...\n");						// 파일 읽는 중 출력
	store = bufjoin("", "");									// 저장 문자열 동적할당 및 초기화
	FILE *fp = fopen("schedule.dat", "r");
	if (fp == '\0')
	{
		printf("\nOpen fail\nCheck \'schedule.dat\' path or file\n\n");
		exit (EXIT_FAILURE);
	}
	while (feof(fp) == 0)
	{
		count = fread(buf, sizeof(char), BUFFSIZE, fp);
		buf[count] = '\0';
		store = bufjoin(store, buf);
	}
	fclose(fp);
	close(fd);													// 열었던 파일 닫기
	return(store);												// .dat 파일에서 읽어들인 문자열의 주소값 반환
}

char *parsing_string(t_sche *l_sche, char *schedule, int flag)
{
	char *str;													// 잠깐 저장 할 문자열

	str = malloc(sizeof(char));									// 동적할당
	str[0] = '\0';												// 저장소 초기화
	while (*schedule != ' ')									// 공백이 나오기 전까지
	{
		str = join_character(str, *schedule);					// 저장소에 현재 문자를 붙임
		schedule++;												// 다음 문자로 넘어감
	}
	if (flag == 0)												// flag가 0이면 work에 저장
		l_sche->work = str;
	if (flag == 1)												// flag가 1이면 location에 저장
		l_sche->location = str;
	return(schedule);											// 지금까지 확인하고 넘어간 스케쥴 문자열 주소값 반환
}

char *parsing_integer(t_sche *l_sche, char *schedule, int flag)
{
	int parsing_value;											// 저장 할 변수

	parsing_value = 0;											// 변수 초기화
	while (*schedule != ' ' && *schedule != 10 && *schedule != 13)			// 공백이거나 개행이거나 CR이 아닐때까지
	{
		parsing_value = join_integer(parsing_value, (*schedule - '0'));		// 스케쥴 문자열의 숫자를 읽어서 정수로 변환해 저장함
		schedule++;															// 다음 문자로 이동
	}
	if (flag == 2)															// flag가 2 이면
		l_sche->type = parsing_value;										// type 에 저장
	if (flag == 3)															// 3이면
		l_sche->month = parsing_value;										// 월에 저장
	if (flag == 4)															// 4이면
		l_sche->day = parsing_value;										// 일에 저장
	return(schedule);														// 지금 까지 넘어간 문자열 주소값 반환
}

t_sche *parse(char *schedule)
{
	int flag;														// 어디를 읽고 있는지 나타내는 flag변수
	int schedule_count;												// 몇 개의 스케쥴이 있는지 저장하는 변수
	t_sche *element;												// 링크드 리스트 연결용
	t_sche *head;													// 링크드 리스트 첫 시작

	schedule_count = 0;												// 스케쥴 갯수 초기화
	element = malloc(sizeof(t_sche));								// 구조체 동적할당
	element->next = NULL;											// 일단 생성 직후에는 다음 연결된 구조체가 없음
	head = element;													// 링크드 리스트의 시작 주소값 저장
	flag = 0;														// flag 변수 초기화
	while (*schedule)												// 읽어온 문자열이 있을때까지 반복
	{
		if (*schedule == '\n' || *schedule == 13)					// 줄바꿈 또는 CR 케리지 리턴이면 다음 스케쥴로 넘어감
		{
			flag = 0;												// flag 다시 0으로 초기화
			schedule_count++;										// 스케쥴 갯수 한개 추가
			add_node(element);										// 다음 노드 추가
			element = element->next;								// 생성한 노드를 링크드 리스트에 연결
			schedule++;												// 다음 문자로 이동
		}
		if (*schedule == ' ')										// 다음 문자가 공백이면
		{
			flag++;													// flag 를 한개 증가
			schedule++;												// 다음 문자열 이동
		}
		else if (isalpha(*schedule) && flag == 0)					// flag가 0이고 현재 문자가 알파벳이면
			schedule = parsing_string(element, schedule, flag);		// 공백이 나오기 전까지 읽음, flag 가 0이므로 work(스케쥴 내용)에 저장
		else if (isalpha(*schedule) && flag == 1)					// flag가 1이고 현재 문자가 알파벳이면
			schedule = parsing_string(element, schedule, flag);		// 공백이 나오기 전까지 읽음, flag 가 1 이므로 location에(장소)에 저장
		else if (isdigit(*schedule) && flag == 2)					// flag가 2이고 현재 문자가 숫자이면
			schedule = parsing_integer(element, schedule, flag);	// 스케쥴 타입에 저장
		else if (isdigit(*schedule) && flag == 3)					// flag가 3이고 현재 문자가 숫자이면
			schedule = parsing_integer(element, schedule, flag);	// 스케쥴 월에 저장
		else if (isdigit(*schedule) && flag == 4)					// flag가 4이고 현재 문자가 숫자이면
			schedule = parsing_integer(element, schedule, flag);	// 스케쥴의 일에 저장
		else
			schedule++;												// 나머지는 그냥 지나감
	}
	printf("Read done!  %d schedules are read\n", schedule_count);	// 읽기 완료 되면 몇 개의 스케쥴이 있는지 출력
	return (head);													// 링크드 리스트 시작 주소값 반환
}
