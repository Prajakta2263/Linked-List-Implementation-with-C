#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create(char[],char[],int);
void display();
void delete(char[]);
struct student
{
    char name[10];
    char event[30];
    int semester;
    struct student *next;
};
struct student *head;
void main()
{
    int choice,sem;
    char s[10],eve[30],key[10];
    do
    {
        printf("1.Add participant details\n2.Delete participant\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the participant name : ");
            scanf("%s",s);
            printf("\nEnter the event name : ");
            scanf("%s",eve);
            printf("\nEnter the participant semester : ");
            scanf("%d",&sem);
            create(s,eve,sem);
            break;
        case 2:
            printf("\nEnter the member name to be deleted\n");
            scanf("%s",key);
            delete(key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default :
            printf("\nPlease enter valid choice\n");
        }
    }while(choice!=4);
}
void create(char s[10],char eve[10],int sem)
{
    struct student *ptr=(struct student*)malloc(sizeof(struct student));
    struct student *temp;
    if(ptr==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        if(head==NULL)
        {
            ptr->next=NULL;
            strcpy(ptr->name,s);
            strcpy(ptr->event,eve);
            ptr->semester=sem;
            head=ptr;
        }
        else
        {
            for(temp=head;temp->next!=NULL;temp=temp->next)
                ;
            strcpy(ptr->name,s);
            strcpy(ptr->event,eve);
            ptr->semester=sem;
            ptr->next=NULL;
            temp->next=ptr;
        }
        printf("__Participant details added__\n");
        printf("\n");
    }
}
void delete(char key[10])
{
     struct student *temp = head,*ptr;
    while(strcmpi(temp->name,key)!=0)
    {
        if(temp->next==NULL)
        {
            printf("Participant not found...");
            exit(0);
        }
        ptr=temp;
        temp=temp->next;
    }
        ptr->next=temp->next;
        free(temp);
        printf("\n__Participant deleted___\n");
}
void display()
{
    struct student *temp;
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("Name : %s\n",temp->name);
            printf("Event registered : %s\n",temp->event);
            printf("Semester : %d\n",temp->semester);
            temp=temp->next;
        }
    }
}
