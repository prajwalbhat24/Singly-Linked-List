#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *nextlink;
};
struct node *head = NULL;

void insertFirst(int tempData)
{
   
        
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->data = tempData;

    link->nextlink = head;

    head = link;
     printf("\nElement Added Succesfully..!!");
}

void insertEnd(int tempData)
{
    if (head==NULL)
    {
       
        insertFirst(tempData);
    }
    else
    {

        if (head->nextlink==NULL)
        {
            struct node* link = (struct node*) malloc(sizeof(struct node));
           link->data = tempData;
           head->nextlink = link;
           printf("\nElement Deleted Succesfully..!!");

        }
        
        else
        {
            struct node* link = (struct node*) malloc(sizeof(struct node));
        struct node *last = head->nextlink;
        link->data = tempData;

        while (last->nextlink != NULL) 
        last = last->nextlink; 

        last->nextlink = link;
        printf("\nElement Deleted Succesfully..!!");

        }
        
        
    }

    
}

void deleteFirst()
{
    struct node *toDelptr;

   
    
    if(head==NULL)
    {
        printf("\nNo Node To Delete.");
    }
    else
    {
        toDelptr = head;
        head = head->nextlink;
        printf("\nElement Deleted Succesfully..!!");
        free(toDelptr);
    }
    

}

void deleteEnd()
{
   
    struct node *tempLast, *preNode;
    if(head==NULL)
    {
        printf("\nNo Node To Delete.");
    }
    else
    {
        tempLast = head;
        preNode = head;
       
        while(tempLast->nextlink != NULL)
        {
            preNode = tempLast;
            tempLast = tempLast->nextlink;
        }
        if(tempLast == head)
        {
            head = NULL;
        }
        else
        {

           
            preNode->nextlink = NULL;
            printf("\nElement Deleted Succesfully..!!");
            free(tempLast);
        }
 
        
        
    }
    

}
void findHeadTail()
{
    if(head==NULL)
    {
        printf("\nLinked List Is Empty.");
    }
    else if(head->nextlink==NULL)
    {
        printf("\nThere is only one element in the linked list.");
        printf("\nSo head and tail are the same i.e.  %d",head->data);
    }
    else
    {
        struct node *last = head->nextlink;
        while (last->nextlink != NULL) 
        last = last->nextlink;
        printf("Head Node : %d ",head->data);
        printf("\nTail Node : %d ",last->data);
    }
    
}
void printList() {

if(head==NULL)
    {
        printf("\nLinked List Is Empty.");
    }
    else
    {
        struct node *ptr = head;
        printf("\n|  Data  |  Next Address  |");
        //printf("\n[head] =>");
   
   while(ptr != NULL) {        
      printf("\n [ %d ]   [ %p ]",ptr->data,ptr->nextlink);
      ptr = ptr->nextlink;
   }

   
    }
    
   
}

int main(void)
{
    int ch;
    int tData;
    while (1)
    {
        printf("\n*******************");
        printf("\n1: Insert First.\n2: Delete First.");
        printf("\n3: Insert End.\n4: Delete End.");
        printf("\n5: Find Head & Tail.");
        printf("\n9: Display All Nodes.\n0: Exit.");
        printf("\n*******************");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("\nEnter The Data : ");
            scanf("%d",&tData);
            insertFirst(tData);
        }
        else if(ch==2)
        {
            deleteFirst();
        }
        else if (ch==3)
        {
            printf("\nEnter The Data : ");
            scanf("%d",&tData);
            insertEnd(tData);
        }
        else if (ch==4)
        {
            deleteEnd();
        }
        else if (ch==5)
        {
            findHeadTail();
        }
        else if(ch==0)
        {
            printf("\nBye-Bye\n");
            exit(0);
        }
        else if(ch==9)
        {
            printList();
        }
        else
        {
            printf("\nInvalid Choice.");
            
        }
        
    }
    
    
}