#include "schedule.h"

char	*bufjoin(char *str1, char *str2)					// 두개의 문자열을 합치는 함수
{
	int i;
	int len1;												// str1 길이
	int len2;												// str2 길이
	char *res;												// 반환 문자열

	i = 0;
	len1 = strlen(str1);									// str1 길이 저장
	len2 = strlen(str2);									// str2 길이 저장
	res = malloc(sizeof(char) * (len1 + len2 + 1));			// str1 + str2 길이 만큼 동적할당
	while (i < (len1 + len2))								// 총 문자열 길이만큼 반복
	{
		if (i < len1 && str1[i])							// len1 보다 작고 str1이 NULL이 아니면
			res[i] = str1[i];								// 반환 문자열에 저장
		if (i >= len1 && str2[i - len1])					// len1 보다 크고 str2 문자열이 존재하면
			res[i] = str2[i - len1];						// 반환 문자열에 저장
		i++;												// 다음 문자로 이동
	}
	res[i] = '\0';											// 문자열 마지막에 NULL입력
	return (res);											// 문자열 반환
}

char *join_character(char *str, char a)						// 문자열에 한개 캐릭터 붙이는 함수
{
	char *ret;												// 반환 문자열
	int len;
	int i;

	i = 0;
	len = strlen(str);										// 문자열 길이
	ret = malloc(sizeof(char) * (len + 1 + 1));				// 문자열 길이 + 문자 1개 만큼 동적할당
	while (i < len + 1)										// 총 문자열 길이 만큼 반복
	{
		if (i < len)										// 입력 문자열 길이보다 작으면
			ret[i] = str[i];								// 입력 문자열에 문자를 반환용 문자열에 저장
		if (i == len)										// 입력 문자열 길이랑 같으면
			ret[i] = a;										// 뒤에 붙일 캐릭터를 반환용 문자열에 저장
		i++;												// 다음 문자열로 이동
	}
	ret[i] = '\0';											// 반환용 문자열 마지막에 NULL 입력
	return (ret);											// 문자열 반환
}

int join_integer(int a, int b)									// 2개의 정수를 2자리 수 정수로 만드는 함수
{
	return ((10 * a) + b);										// 10 * a + b 한 값을 반환
}

void del_memory(t_sche *lst, char *str)		// 동적할당 메모리 회수
{
	t_sche *target;							// 회수할 메모리 주소 저장
	t_sche *temp;							// 다음 메모리 주소 저장

	target = lst;							// 처음 시작점 주소값 저장
	temp = target;							// 시작점 저장
	while (target != NULL)					// 링크드리스트가 끝날 때까지 이동
	{
		temp = temp->next;					// 다음 리스트 주소값 저장
		free(target);						// 현재 리스트 메모리 회수
		target = temp;						// 다음 리스트로 이동
	}
	free (str);								// .dat 파일에서 읽어온 스케쥴 문자열 메모리 회수
}
