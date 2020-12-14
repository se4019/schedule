#include "schedule.h"

int main(void)
{
	char *schedule;						// schedule.dat ������ �о�� ���ڿ��� �����ϴ� ����
	t_sche *worklist;					// �����쿡�� �о�� ���ڿ����� ������ ���� ��ũ�� ����Ʈ�� �����ϴ� ����ü

	schedule = readfile();				// .dat������ �о�� schedule ���ڿ��� �����Ѵ�.
	worklist = parse(schedule);			// schedule ���ڿ����� ������ ���� �ɰ��� ��ũ�帮��Ʈ�� �����Ѵ�.
	select_option(worklist);			// �ɼ��� �����ϰ� ����� ����ϴ� �Լ�
	del_memory(worklist, schedule);		// �����Ҵ��� �޸𸮸� ȸ���ϴ� �Լ�
	return (0);							// ���α׷� ����
}
