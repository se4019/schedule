#include "schedule.h"

static char month_string[13][4] =				// �� ���� �迭
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

char type_string[MAX_TYPE][20] =				// Ÿ�� ���ڷ� ��ȯ�ϴ� �迭
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

void print_messege(void)							// �ɼ� ����â ���
{
	printf("\n\n\n");
	printf("1. print all the schedules\n");
	printf("2. search for schedules in the month\n");
	printf("3. search for schedules in the place\n");
	printf("4. search for specific type schedule\n");
	printf("5. exit\n\n");
	printf("select an option : ");
}

void print_haeder(void)
{
	printf("\n\n\n");									//��� ��½� ���� ���� ���
}

void print_schedule(t_sche *search)						// ��� ���
{
	printf("---------------------------------------------\n");
	printf("1. Schedule Name : %s (%s)\n", search->work, type_string[search->type]);
	printf("When : %s. %d\n", month_string[search->month], search->day);
	printf("Where : %s\n", search->location);
}

void print_end_bar(void)								// ����� ��� ��� �� �������� ���
{
	printf("---------------------------------------------\n");
}
