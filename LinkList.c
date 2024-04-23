

#include <stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node *link;

};
void print_data(struct node *head){
    if(head == NULL)
        printf("Linked List is empy");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
    

}

void add_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));

    temp ->data = data;
    temp-> link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr ->link = temp;
    
}


void add_at_pos(struct node* head, int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2 ->data = data;
    ptr2->link =NULL;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2 ->link = ptr->link;
    ptr->link = ptr2;
    
}
void del_pos(struct node **head, int dposition){
    struct node *current = *head;
    struct node *previous = *head;
    if (*head == NULL)
    {
        printf("List is already empty");
    }
    else if (dposition ==1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while (dposition != 1)
        {
            previous = current;
            current = current->link;
            dposition --;
        }
        previous ->link = current->link;
        free(current);
        current =NULL;
        
    }
    
    

}

int main()
{
    
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    
    struct node *current = malloc(sizeof(struct node));
    current->data =98;
    current->link = NULL;
    head->link = current;

    struct node *current2 = malloc(sizeof(struct node));
    current2 ->data = 3;
    current2 -> link = NULL;
    current->link = current2;

    int data = 67, aposition =3;
    int dposition = 2;
    

    print_data(head);
    add_at_pos(head, data, aposition);
    struct node *ptr =head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    del_pos(&head, dposition);
    print_data(head);
    

}

