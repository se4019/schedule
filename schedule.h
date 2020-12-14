#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFSIZE 32								// .dat ���Ͽ��� �� ���� �о�� ������ ������ �����ϴ� ����
#define MAX_TYPE 7								// ��ü type ���� type_string ����ü���� ����� ����

typedef struct	s_sche							// ������ ����ü
{
	char *work;									// ������ ����
	char *location;								// ������ ���
	int type;									// ������ Ÿ��
	int month;									// ��
	int day;									// ��
	struct s_sche *next;						// ��ũ�帮��Ʈ ���� ����ü �ּҰ�
}				t_sche;

//util.c
char	*bufjoin(char *str1, char *str2);		// 2���� ���ڿ��� ���̴� �Լ�
char	*join_character(char *str, char a);		// ���ڿ��� 1���� ĳ���͸� ���̴� �Լ�
int		join_integer(int a, int b);				// ������ �������� ��ġ�� �Լ�
void	del_memory(t_sche *lst, char *str);		// �����Ҵ� �޸� ȸ��

//parsing.c
char	*readfile(void);						// .dat ������ �о���� �Լ�
char	*parsing_string(t_sche *l_sche, char *schedule, int flag);	// .dat���� schedule ���ڿ��� �ű� �� �߿� ���ڿ� ������ ����ü�� ����
char	*parsing_integer(t_sche *l_sche, char *schedule, int flag);	// .dat���� schedule ���ڿ��� �ű� �� �߿� ������ ������ ����ü�� ����
t_sche	*parse(char *schedule);										// .dat���� schedule ���ڿ��� �ű� ���� �����캰�� �ɰ��� ��ũ�帮��Ʈ�� ����� �Լ�

//linkedlist.c
void add_node(t_sche *target);					// ��ũ�� ����Ʈ�� ���� ��带 �߰��ϴ� �Լ�

//print.c
void print_messege(void);						// �ɼ� ���� �޼��� ���
void print_haeder(void);						// ��� ��½� �� �� ���� ���
void print_schedule(t_sche *search);			// ��� ���
void print_end_bar(void);						// ��� ��� ��� �� �ٴ� �κ� bar ���

//select_option.c
void select_option(t_sche *worklist);			// �ɼ� ������ �Է� �޾Ƽ� Ž�� �� ��� ��� �Լ��� ȣ���ϴ� �Լ�
