#include "schedule.h"

char	*readfile(void)
{
	char buf[BUFFSIZE];											// ���� ������ ������ŭ �о�鿩�� ������ �迭
	int fd;														// ���� ��ũ����
	int ret;													// ���� ��
	char *store;												// �ӽ� ���ۿ� �о�鿩�� ���� ������ ���ڿ�
	int count;
	
	printf("Reading the data files...\n");						// ���� �д� �� ���
	store = bufjoin("", "");									// ���� ���ڿ� �����Ҵ� �� �ʱ�ȭ
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
	close(fd);													// ������ ���� �ݱ�
	return(store);												// .dat ���Ͽ��� �о���� ���ڿ��� �ּҰ� ��ȯ
}

char *parsing_string(t_sche *l_sche, char *schedule, int flag)
{
	char *str;													// ��� ���� �� ���ڿ�

	str = malloc(sizeof(char));									// �����Ҵ�
	str[0] = '\0';												// ����� �ʱ�ȭ
	while (*schedule != ' ')									// ������ ������ ������
	{
		str = join_character(str, *schedule);					// ����ҿ� ���� ���ڸ� ����
		schedule++;												// ���� ���ڷ� �Ѿ
	}
	if (flag == 0)												// flag�� 0�̸� work�� ����
		l_sche->work = str;
	if (flag == 1)												// flag�� 1�̸� location�� ����
		l_sche->location = str;
	return(schedule);											// ���ݱ��� Ȯ���ϰ� �Ѿ ������ ���ڿ� �ּҰ� ��ȯ
}

char *parsing_integer(t_sche *l_sche, char *schedule, int flag)
{
	int parsing_value;											// ���� �� ����

	parsing_value = 0;											// ���� �ʱ�ȭ
	while (*schedule != ' ' && *schedule != 10 && *schedule != 13)			// �����̰ų� �����̰ų� CR�� �ƴҶ�����
	{
		parsing_value = join_integer(parsing_value, (*schedule - '0'));		// ������ ���ڿ��� ���ڸ� �о ������ ��ȯ�� ������
		schedule++;															// ���� ���ڷ� �̵�
	}
	if (flag == 2)															// flag�� 2 �̸�
		l_sche->type = parsing_value;										// type �� ����
	if (flag == 3)															// 3�̸�
		l_sche->month = parsing_value;										// ���� ����
	if (flag == 4)															// 4�̸�
		l_sche->day = parsing_value;										// �Ͽ� ����
	return(schedule);														// ���� ���� �Ѿ ���ڿ� �ּҰ� ��ȯ
}

t_sche *parse(char *schedule)
{
	int flag;														// ��� �а� �ִ��� ��Ÿ���� flag����
	int schedule_count;												// �� ���� �������� �ִ��� �����ϴ� ����
	t_sche *element;												// ��ũ�� ����Ʈ �����
	t_sche *head;													// ��ũ�� ����Ʈ ù ����

	schedule_count = 0;												// ������ ���� �ʱ�ȭ
	element = malloc(sizeof(t_sche));								// ����ü �����Ҵ�
	element->next = NULL;											// �ϴ� ���� ���Ŀ��� ���� ����� ����ü�� ����
	head = element;													// ��ũ�� ����Ʈ�� ���� �ּҰ� ����
	flag = 0;														// flag ���� �ʱ�ȭ
	while (*schedule)												// �о�� ���ڿ��� ���������� �ݺ�
	{
		if (*schedule == '\n' || *schedule == 13)					// �ٹٲ� �Ǵ� CR �ɸ��� �����̸� ���� ������� �Ѿ
		{
			flag = 0;												// flag �ٽ� 0���� �ʱ�ȭ
			schedule_count++;										// ������ ���� �Ѱ� �߰�
			add_node(element);										// ���� ��� �߰�
			element = element->next;								// ������ ��带 ��ũ�� ����Ʈ�� ����
			schedule++;												// ���� ���ڷ� �̵�
		}
		if (*schedule == ' ')										// ���� ���ڰ� �����̸�
		{
			flag++;													// flag �� �Ѱ� ����
			schedule++;												// ���� ���ڿ� �̵�
		}
		else if (isalpha(*schedule) && flag == 0)					// flag�� 0�̰� ���� ���ڰ� ���ĺ��̸�
			schedule = parsing_string(element, schedule, flag);		// ������ ������ ������ ����, flag �� 0�̹Ƿ� work(������ ����)�� ����
		else if (isalpha(*schedule) && flag == 1)					// flag�� 1�̰� ���� ���ڰ� ���ĺ��̸�
			schedule = parsing_string(element, schedule, flag);		// ������ ������ ������ ����, flag �� 1 �̹Ƿ� location��(���)�� ����
		else if (isdigit(*schedule) && flag == 2)					// flag�� 2�̰� ���� ���ڰ� �����̸�
			schedule = parsing_integer(element, schedule, flag);	// ������ Ÿ�Կ� ����
		else if (isdigit(*schedule) && flag == 3)					// flag�� 3�̰� ���� ���ڰ� �����̸�
			schedule = parsing_integer(element, schedule, flag);	// ������ ���� ����
		else if (isdigit(*schedule) && flag == 4)					// flag�� 4�̰� ���� ���ڰ� �����̸�
			schedule = parsing_integer(element, schedule, flag);	// �������� �Ͽ� ����
		else
			schedule++;												// �������� �׳� ������
	}
	printf("Read done!  %d schedules are read\n", schedule_count);	// �б� �Ϸ� �Ǹ� �� ���� �������� �ִ��� ���
	return (head);													// ��ũ�� ����Ʈ ���� �ּҰ� ��ȯ
}
