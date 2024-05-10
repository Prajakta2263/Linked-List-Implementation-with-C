#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create(char[],char[],char[],char[],char[]);
void search(char[]);
struct node
{
    char p_name[10];
    char b_grp[10];
    char b_pre[10];
    char diabetes[10];
    char other[10];
    struct node *next;
};
struct node *head;
void main()
{
    int choice;
    char name[10],bg[10],bp[10],dia[10],oth[10],bgkey[10];
    do
    {
        printf("\n1.Enter donar details\n2.Search blood group\n3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the donar's name : ");
            scanf("%s",name);
            printf("Enter the Blood Group : ");
            scanf("%s",bg);
            printf("Donar has Blood Pressure ? : ");
            scanf("%s",bp);
            printf("Donar has Diabetes ? : ");
            scanf("%s",dia);
            printf("Any other disease : ");
            scanf("%s",oth);
            create(name,bg,bp,dia,oth);
            break;
        case 2:
            printf("\nEnter the Blood group to be searched : ");
            scanf("%s",bgkey);
            search(bgkey);
            break;
        case 3:
            exit(0);
            break;
        default :
            printf("\nPlease enter valid choice\n");
        }
    }while(choice!=3);
}
void create(char name[10],char bg[10],char bp[10],char dia[10],char oth[10])
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    if(ptr==NULL)
    {
        printf("\nERROR...\n");
    }
    else
    {
        if(head==NULL)
        {
            ptr->next=NULL;
            strcpy(ptr->p_name,name);
            strcpy(ptr->b_grp,bg);
            strcpy(ptr->b_pre,bp);
            strcpy(ptr->diabetes,dia);
            strcpy(ptr->other,oth);
            head=ptr;
        }
        else
        {
            for(temp=head;temp->next!=NULL;temp=temp->next)
                ;
            strcpy(ptr->p_name,name);
            strcpy(ptr->b_grp,bg);
            strcpy(ptr->b_pre,bp);
            strcpy(ptr->diabetes,dia);
            strcpy(ptr->other,oth);
            ptr->next=NULL;
            temp->next=ptr;
        }
        printf("\nDetails added\n");
        printf("\n");
    }
}
void search(char bgkey[10])
{
     struct node *temp = head;
     int found=0;
        if(temp==NULL)
        {
            printf("Records not found\n");
        }
        else
        {
            while(temp!=NULL)
            {
                if(strcmpi(temp->b_grp, bgkey)==0)
                {
                    printf("NAME : %s\n",temp->p_name);
                    printf("BLOOD GROUP : %s\n",temp->b_grp);
                    printf("BLOOD PRESSURE : %s\n",temp->b_pre);
                    printf("DIABETES : %s\n",temp->diabetes);
                    printf("OTHER DISEASE : %s\n",temp->other);
                    found=1;
                }
            temp=temp->next;
            }
            if(found==0)
            {
                printf("Records not found\n");
            }
        }

}
