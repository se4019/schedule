#include "schedule.h"

void add_node(t_sche *origin)					// ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
	t_sche *newnode = malloc(sizeof(t_sche));	// �� ��� ����
	newnode->next = origin->next;				// �� ����� ���� ��忡 ���� ����� ���� ��带 ����
	origin->next = newnode;						// ���� ����� ���� ��忡 �� ��带 ����
}
