#include <stdio.h>
#include <stdlib.h>

struct list
{
    int info;
    struct list *next;
};
struct list *ptr, *p, *start=NULL, *rear=NULL;

void new_node (int n)
{
    ptr = (struct list *) malloc (sizeof(struct list));
    if (ptr==NULL)
    {
        printf("\nMemory could not be allocated!\n");
        return;
    }
    ptr->info = n;
    ptr->next = NULL;
}

int tot ()
{
    int c=0;
    if (start == NULL)
        return c;
    p=start;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

void display ()
{
    if (tot()==0)
    {
        printf("\nList is empty, nothing to display!\n");
        return ;
    }  
    p=start->next;
    printf("\nList items: %d", start->info);
    while (p!=NULL)
    {
        printf(" -> %d", p->info);
        p = p->next;
    }
    printf(" -> NULL\n");
}

void insert_end (int n)
{
    new_node(n);
    if (tot()==0)
    {
        start = ptr;
        rear = ptr;
        return ;
    }
    rear->next = ptr;
    rear = ptr;
}

int min_list ()
{
    if (tot()==0)
        printf("\nList is empty!\n");
    else
    {
        int mn = start->info;
        p = start->next;
        while (p != NULL)
        {
            if (mn > p->info)
                mn = p->info;
            p = p->next;
        }
        return mn;
    }
    return -32767;
}

int main()
{
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n");

    int ch,n,k,key;
    while (1)
    {
        printf("\nMENU:\n1. Insert at end\n2. Print minimum element in list\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("\nEnter the element to be inserted: ");
                    scanf("%d", &n);
                    insert_end(n);
                    display();
                    break;
            case 2: display();
                    if (tot()!=0)
                        printf("\nMinimum element in linked list is: %d\n", min_list());
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong choice! Enter again...\n");
        }
    }
    return 0;
}