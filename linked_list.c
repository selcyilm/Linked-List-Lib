#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int	value;
	struct node *next;
} Node;

void	ft_print_node(Node *head);
int	ft_nodelen(Node *head);
Node *ft_insert_add_head(Node *head, int value);
Node *ft_insert_add_tail(Node *head, int value);

int	main()
{
	Node *list1_head;

	list1_head = NULL;
	list1_head = ft_insert_add_tail(list1_head,5);
	list1_head = ft_insert_add_tail(list1_head,4);
	list1_head = ft_insert_add_tail(list1_head,3);
	list1_head = ft_insert_add_tail(list1_head,2);

	ft_print_node(list1_head);
	printf("Here is the %d of nodes\n", ft_nodelen(list1_head));
}

Node *ft_insert_add_head(Node *head, int value)
{
	Node *new_node;

	new_node = calloc(1, sizeof(Node));
	new_node->value = value;
	if (head == NULL)
		return (new_node);
	else
	{
		new_node->next = head;
		return (new_node);
	}
}

Node *ft_insert_add_tail(Node *head, int value)
{
	Node *new_node;
	Node *current;

	current = head;
	new_node = calloc(1, sizeof(Node));
	new_node->value = value;
	if (head == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		return (head);
	}
}

void	ft_print_node(Node *head)
{
	Node *current;
	int	i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

int	ft_nodelen(Node *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}