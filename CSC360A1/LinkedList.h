#ifndef	_LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct Node Node;

struct Node
{
	pid_t pid;
	char *path;
	Node *next;
};

Node* addNode(Node* head, pid_t newPid, char *newPath);
Node* removeNode(Node* head, pid_t pid);
int exists(pid_t pid);
void printlist(Node* head);

#endif
