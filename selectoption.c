#include "schedule.h"

static void all_search(t_sche *search)					// ��� �������� ����ϴ� �Լ�
{
	print_haeder();										// ��� ���� ���
	while (search->next)								// ��ũ�帮��Ʈ�� ����������
	{
		print_schedule(search);							// ������ ���
		search = search->next;							// ���� ����ü�� �̵�
	}
	print_end_bar();									// ����� ��� ��� �� �������� ���
}

static void place_search(t_sche *search)				// ��Ҹ� ã�Ƽ� ���
{
	char place[100];									// ��Ҹ� �Է¹޾� �����ϴ� �迭
	int flag;											// flag ����

	flag = 0;											// flag �ʱ�ȭ
	printf("Which place ? : ");							// ��� ������� �Է��ϴ� ���ڿ� ���
	scanf("%s", place);									// �Է¹ޱ�
	while (search->next)								// ��ũ�帮��Ʈ ���� �˻�
	{
		if ((strcmp(place, search->location)) == 0)		// �Է� ���� ���� ������
		{
			flag++;										// flag�� �ϳ� ����
			if (flag == 1)								// flag�� 1 �϶��� ��� ���
				print_haeder();
			print_schedule(search);						// ��ġ �� ��� ���
		}
		search = search->next;							// ���� ��ũ�帮��Ʈ�� �̵�
	}
	print_end_bar();									// ��� ��� ��� �� �������� ���
}

static void month_search(t_sche *search)				// ���� �˻�
{
	int month_input;									// �Է¹��� ��
	int flag;											// �÷���

	flag = 0;											// �÷��� �ʱ�ȭ
	while (1)											// �ݺ�
	{
		printf("Which month ? : ");						// �� �Է� ����
		scanf("%d", &month_input);						// �� �Է�
		if (month_input >= 1 && month_input <= 12)		// 1 ~ 12 ���� �Է� ������ �ݺ� ����
			break;
	}
	while (search->next)								// ��� ��ũ�帮��Ʈ �˻�
	{
		if (search->month == month_input)				// �Է¹��� ���� ���� ���̸�
		{
			flag++;										// �÷��� 1 ����
			if (flag == 1)								// �÷��װ� 1�̸� ��� ���
				print_haeder();
			print_schedule(search);						// ��� ���
		}
		search = search->next;							// ���� ��ũ�� ����Ʈ�� �̵�
	}
	print_end_bar();									// �������� ���
}

static void type_search(t_sche *search)					// ���� Ÿ���� ������ �˻�
{
	char type[100];										// ������ �Է�
	int type_input;										// �Է¹��� �������� ������ ��ȯ
	int flag;											// �÷���
	extern char type_string[MAX_TYPE][20];				// ������ ���ڿ� ����ü

	flag = 0;											// �÷��� �ʱ�ȭ
	type_input = 0;										// �Է¹��� Ÿ�� �ʱ�ȭ
	printf("Which type ? : ");							// � Ÿ�� ���������� �Է�
	scanf("%s", type);									// �Է� �޾� �迭�� ����
	while (type_string[type_input] != '\0')				// 0���� 7���� Ÿ�� ���ڿ� ���� �˻�
	{
		if ((strcmp(type, type_string[type_input])) == 0)		// �Է¹��� ���� ��ġ�ϴ� ���� ������
			break;												// �ݺ��� ����
		type_input++;											// �Է¹��� Ÿ�� ������ �ϳ� �������� �ٽ� �˻�
		if (type_input == 7)									// �Է¹��� ���� ����� Ÿ�� ���ڿ��� ��ġ�ϴ� ���� ������ ����
		{
			printf("Input Right schedule type\n");				// ��� �� ����
			return;
		}
	}

	while (search->next)										// ��� ��ũ�帮��Ʈ �˻�
	{
		if (search->type == type_input)							// �Է¹��� Ÿ�԰��� ��ġ�ϴ� �������� ������
		{
			flag++;												// �÷��׸� 1 ������Ŵ
			if (flag == 1)										// �÷��װ� 1�̸� ��� ���
				print_haeder();
			print_schedule(search);								// ������
		}
		search = search->next;									// ���� ����Ʈ�� �̵�
	}
	print_end_bar();											// �������� ���
}

void select_option(t_sche *worklist)							// �ɼ��� �����ϴ� �Լ�
{
	int num;													// �Է¹��� �ɼ�
	t_sche *search;												// ��ũ�� ����Ʈ �̵��� ���

	search = worklist;											// �̵��� ����� ����ü�� ó�� ���۰� ����
	while (1)													// 5�� ���� �� ����ñ��� �ݺ�
	{
		print_messege();										// �ɼ� ���� ���ڿ� ���
		scanf("%d", &num);										// �ɼ� �Է¹ޱ�
		if (num == 1)											// 1�̸�
			all_search(search);									// ��� ������ ���
		else if (num == 2)										// 2�̸� ���� ������ ���
			month_search(search);
		else if (num == 3)										// 3�̸� ��Һ� ������ ���
			place_search(search);
		else if (num == 4)										// 4�̸� Ÿ�Ժ� ������ ���
			type_search(search);
		else if (num == 5)										// 5�̸� ����
			break;
		else
			continue ;
	}
}
