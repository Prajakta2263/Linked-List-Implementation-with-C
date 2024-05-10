#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bcreate(char[],char[]);
void dcreate(char[],char[]);
void s_name(char[]);
void s_date(char[]);
void display();
struct node
{
    char name[10];
    char date[10];
    struct node *next;
};
struct node *bhead,*dhead;
void main()
{
    int choice;
    char bname[10],dname[10],nkey[10],dkey[10],bdate[10],ddate[10];
    do
    {
        printf("\n1.Birth Registration\n2.Death Registration\n3.Search records with name\n4.Search records by date\n5.Display\n6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the Name to be registered : ");
            scanf("%s",bname);
            printf("Enter the Date Of Birth(dd/mm/yyyy) : ");
            scanf("%s",bdate);
            bcreate(bname,bdate);
            break;
        case 2:
            printf("\nEnter the Name to be registered : ");
            scanf("%s",dname);
            printf("\nEnter the Date Of Death(dd/mm/yyyy) : ");
            scanf("%s",ddate);
            dcreate(dname,ddate);
            break;
        case 3:
            printf("\nEnter Name to search records : ");
            scanf("%s",nkey);
            s_name(nkey);
            break;
        case 4:
            printf("\nEnter Date to search records(ddmmyyyy) : ");
            scanf("%s",dkey);
            s_date(dkey);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default :
            printf("\nPlease enter valid choice\n");
        }
    }while(choice!=6);
}
void bcreate(char bname[10],char bdate[10])
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *temp1;
    if(ptr==NULL)
    {
        printf("\nERROR...\n");
    }
    else
    {
        if(bhead==NULL)
        {
            ptr->next=NULL;
            strcpy(ptr->name,bname);
            strcpy(ptr->date,bdate);
            bhead=ptr;
        }
        else
        {
            for(temp1=bhead;temp1->next!=NULL;temp1=temp1->next)
                ;
            strcpy(ptr->name,bname);
            strcpy(ptr->date,bdate);
            ptr->next=NULL;
            temp1->next=ptr;
        }
        printf("\nBirth registration Sucessful\n");
        printf("\n");
    }
}
void dcreate(char dname[10],char ddate[10])
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *temp2;
    if(ptr==NULL)
    {
        printf("\nERROR...\n");
    }
    else
    {
        if(dhead==NULL)
        {
            ptr->next=NULL;
            strcpy(ptr->name,dname);
            strcpy(ptr->date,ddate);
            dhead=ptr;
        }
        else
        {
            for(temp2=dhead;temp2->next!=NULL;temp2=temp2->next)
                ;
            strcpy(ptr->name,dname);
            strcpy(ptr->date,ddate);
            ptr->next=NULL;
            temp2->next=ptr;
        }
        printf("\nDeath registration Successful\n");
        printf("\n");
    }
}
void s_name(char nkey[10])
{
     struct node *temp1 = bhead;
     int found1=0;
        if(temp1==NULL)
        {
            printf("Records not found\n");
        }
        else
        {
            printf("\n____BIRTH RECORDS____\n");
            while(temp1!=NULL)
            {
                if(strcmpi(temp1->name,nkey)==0)
                {
                    printf("%s\n",temp1->name);
                    printf("%s\n",temp1->date);
                    found1=1;
                }
            temp1=temp1->next;
            }
            if(found1==0)
            {
                printf("Birth records not found\n");
            }
        }
    struct node *temp2 = dhead;
     int found2=0;
        if(temp2==NULL)
        {
            printf("Records not found\n");
        }
        else
        {
            printf("\n____DEATH RECORDS____\n");
            while(temp2!=NULL)
            {
                if(strcmpi(temp2->name,nkey)==0)
            {
                printf("%s\n",temp2->name);
                printf("%s\n",temp2->date);
                found2=1;
            }
            temp2=temp2->next;
            }
            if(found2==0)
            {
                printf("Death records not found\n");
            }
        }
}
void s_date(char dkey[10])
{
    struct node *temp1 = bhead;
     int found1=0;
        if(temp1==NULL)
        {
            printf("Records not found\n");
        }
        else
        {
            printf("\n____BIRTH RECORDS____\n");
            while(temp1!=NULL)
            {
                if(strcmpi(temp1->date,dkey)==0)
            {
                printf("%s\n",temp1->name);
                printf("%s\n",temp1->date);
                found1=1;
            }
            temp1=temp1->next;
            }
            if(found1==0)
            {
                printf("Birth records not found\n");
            }
        }
    struct node *temp2 = dhead;
     int found2=0;
        if(temp2==NULL)
        {
            printf("Records not found\n");
        }
        else
        {
            printf("\n____DEATH RECORDS____\n");
            while(temp2!=NULL)
            {
             if(strcmpi(temp2->date,dkey)==0)
            {
                printf("%s\n",temp2->name);
                printf("%s\n",temp2->date);
                found2=1;
            }
            temp2=temp2->next;
            }
            if(found2==0)
            {
                printf("Death records not found\n");
            }
        }
}
void display()
{
    struct node *temp1;
    {
        temp1=bhead;
        while(temp1!=NULL)
        {
            printf("NAME : %s\t",temp1->name);
            printf("DATE : %s\t\n",temp1->date);
            temp1=temp1->next;
        }
    }
     struct node *temp2;
    {
        temp2=dhead;
        while(temp2!=NULL)
        {
            printf("NAME : %s\t",temp2->name);
            printf("DATE : %s\t\n",temp2->date);
            temp2=temp2->next;
        }
    }
}

