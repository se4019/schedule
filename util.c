#include "schedule.h"

char	*bufjoin(char *str1, char *str2)					// �ΰ��� ���ڿ��� ��ġ�� �Լ�
{
	int i;
	int len1;												// str1 ����
	int len2;												// str2 ����
	char *res;												// ��ȯ ���ڿ�

	i = 0;
	len1 = strlen(str1);									// str1 ���� ����
	len2 = strlen(str2);									// str2 ���� ����
	res = malloc(sizeof(char) * (len1 + len2 + 1));			// str1 + str2 ���� ��ŭ �����Ҵ�
	while (i < (len1 + len2))								// �� ���ڿ� ���̸�ŭ �ݺ�
	{
		if (i < len1 && str1[i])							// len1 ���� �۰� str1�� NULL�� �ƴϸ�
			res[i] = str1[i];								// ��ȯ ���ڿ��� ����
		if (i >= len1 && str2[i - len1])					// len1 ���� ũ�� str2 ���ڿ��� �����ϸ�
			res[i] = str2[i - len1];						// ��ȯ ���ڿ��� ����
		i++;												// ���� ���ڷ� �̵�
	}
	res[i] = '\0';											// ���ڿ� �������� NULL�Է�
	return (res);											// ���ڿ� ��ȯ
}

char *join_character(char *str, char a)						// ���ڿ��� �Ѱ� ĳ���� ���̴� �Լ�
{
	char *ret;												// ��ȯ ���ڿ�
	int len;
	int i;

	i = 0;
	len = strlen(str);										// ���ڿ� ����
	ret = malloc(sizeof(char) * (len + 1 + 1));				// ���ڿ� ���� + ���� 1�� ��ŭ �����Ҵ�
	while (i < len + 1)										// �� ���ڿ� ���� ��ŭ �ݺ�
	{
		if (i < len)										// �Է� ���ڿ� ���̺��� ������
			ret[i] = str[i];								// �Է� ���ڿ��� ���ڸ� ��ȯ�� ���ڿ��� ����
		if (i == len)										// �Է� ���ڿ� ���̶� ������
			ret[i] = a;										// �ڿ� ���� ĳ���͸� ��ȯ�� ���ڿ��� ����
		i++;												// ���� ���ڿ��� �̵�
	}
	ret[i] = '\0';											// ��ȯ�� ���ڿ� �������� NULL �Է�
	return (ret);											// ���ڿ� ��ȯ
}

int join_integer(int a, int b)									// 2���� ������ 2�ڸ� �� ������ ����� �Լ�
{
	return ((10 * a) + b);										// 10 * a + b �� ���� ��ȯ
}

void del_memory(t_sche *lst, char *str)		// �����Ҵ� �޸� ȸ��
{
	t_sche *target;							// ȸ���� �޸� �ּ� ����
	t_sche *temp;							// ���� �޸� �ּ� ����

	target = lst;							// ó�� ������ �ּҰ� ����
	temp = target;							// ������ ����
	while (target != NULL)					// ��ũ�帮��Ʈ�� ���� ������ �̵�
	{
		temp = temp->next;					// ���� ����Ʈ �ּҰ� ����
		free(target);						// ���� ����Ʈ �޸� ȸ��
		target = temp;						// ���� ����Ʈ�� �̵�
	}
	free (str);								// .dat ���Ͽ��� �о�� ������ ���ڿ� �޸� ȸ��
}
