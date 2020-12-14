#include "schedule.h"

void add_node(t_sche *origin)					// 기준 노드 뒤에 노드를 추가하는 함수
{
	t_sche *newnode = malloc(sizeof(t_sche));	// 새 노드 생성
	newnode->next = origin->next;				// 새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
	origin->next = newnode;						// 기준 노드의 다음 노드에 새 노드를 지정
}
