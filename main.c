#include <stdio.h>
#include <stdlib.h>

struct list_elem
{
    void *data;
    struct list_elem *next;
};

void init_list_elem(struct list_elem *elem)
{
    elem->data = NULL;
    elem->next = NULL;
}

struct list_elem *get_last_elem(struct list_elem *head)
{
    struct list_elem *cur = head;
    while (cur != NULL)
    {
        if (cur->next == NULL)
        {
            break;
        }
        cur = cur->next;
    }
    return cur;
}

void add_list_elem(struct list_elem *head, void *data)
{
    if (head->data == NULL)
    {
        head->data = data;
    }
    else
    {
        struct list_elem *new_elem = (struct list_elem *)malloc(sizeof(struct list_elem));
        init_list_elem(new_elem);
        new_elem->data = data;
        struct list_elem *last_elem = get_last_elem(head);
        last_elem->next = new_elem;
    }
}

void destroy_linked_list(struct list_elem *head)
{
    struct list_elem *cur = head->next;
    while (cur != NULL)
    {
        struct list_elem *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(int argc, char **argv)
{
    struct list_elem head;
    init_list_elem(&head);
    add_list_elem(&head, "First!");
    add_list_elem(&head, "Second!");
    add_list_elem(&head, "Third!");

    struct list_elem *cur = &head;
    while (cur != NULL)
    {
        printf("%s\n", (const char *)cur->data);
        cur = cur->next;
    }
    
    destroy_linked_list(&head);
    return 0;
}
