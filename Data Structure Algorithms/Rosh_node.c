#include <stdio.h>
#include <stdlib.h>
struct node //structure creation 
{
    int roll;
    char name[15];
    long salary;
    struct node *next;
} * start;
void add_node();  //function declaration
void Nth_display();
void main()  //main
{

    int op;
  //Process to draw a menu for users to enter choice
    do
    {
        printf("\n_____menu_____");
        printf("\n1.add_node    2.Nth_display     3.exit     \n");
        printf("\nEnter your choice");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add_node();
            break;
        case 2:
            Nth_display();
            break;
        case 3:
            printf("\nBye");
            break;
        default:
            printf("\ninvalid choice");
            break; /* code */
        }

    } while (op != 3);
}                      //end of main
void add_node()   //function for adding nodes to create or elongate the linked list
{
    struct node *ptr, *l;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nThe memory is full");
    }
    else
    {
        printf("\nEnter the roll, name and salary of the intern student");
        scanf("%d %s%ld", &ptr->roll, &ptr->name, &ptr->salary);

        if (start == NULL)
        {
            start = ptr;
            ptr->next = NULL;
        }
        else            //To add newly created node at the last position of the linked list
        {
            l = start;
            while (l->next != NULL)
            {
                l = l->next;
            }
            l->next = ptr;
            ptr->next = NULL;
        }
    }
}
void Nth_display()   //Function to print the information stored in Nth and (N-1)th node
{
    struct node *ptr;
    int n, c = 0;
    printf("\nEnter the valid n value");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("\n Invalid value of n");
        Nth_display();
    }
    ptr = start;
    while (ptr != NULL)
    {
        c++;
        if (c > 1 && (c == n - 1 || c == n))
        {
            printf("\nName=%s       Roll=%d     Salary=%ld\n", ptr->name, ptr->roll, ptr->salary);
        }

        ptr = ptr->next;
    }
    if (c < 2)
    {
        printf("\n At least 2 nodes are required");
    }
    else if (n > c)
    {
        printf("\nThe number of nodes should be greater than or equal to n");
    }
}
