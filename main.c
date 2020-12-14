#include "schedule.h"

int main(void)
{
	char *schedule;						// schedule.dat 파일을 읽어와 문자열로 저장하는 공간
	t_sche *worklist;					// 스케쥴에서 읽어온 문자열에서 스케쥴 별로 링크드 리스트에 저장하는 구조체

	schedule = readfile();				// .dat파일을 읽어와 schedule 문자열에 저장한다.
	worklist = parse(schedule);			// schedule 문자열에서 스케쥴 별로 쪼개서 링크드리스트에 저장한다.
	select_option(worklist);			// 옵션을 선택하고 결과를 출력하는 함수
	del_memory(worklist, schedule);		// 동적할당한 메모리를 회수하는 함수
	return (0);							// 프로그램 종료
}
