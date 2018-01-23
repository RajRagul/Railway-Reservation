#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* head;

struct node* bookwithseat(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=head;
    head=temp;
    return head;
}
struct node* bookwithid(int x,int pos)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=NULL;
    struct node* temp2=head;
    if(pos==1)
    {
     temp->link=head;
     head=temp;
     return head;
    }
    for(int i=0;i<pos-2;i++)
     {
       temp2=temp2->link;
     }
    temp->link=temp2->link;
    temp2->link=temp;
}
void cancelaseat(int dp)
{
 struct node* temp=head;int i;
 struct node* temp2=head;
 for(i=0;i<dp-1;i++)
 {
  temp2=temp2->link;
 }
 for(i=0;i<dp-2;i++)
  {
   temp=temp->link;
  }
  temp->link=temp2->link;
  free(temp2);
}
struct node* cancelanid(int de)
{
 struct node* temp=head;
 struct node* temp2=head; 
 int i,pos=0;
 while(temp->data!=de)
 {
  temp=temp->link;
  pos++;
 }
 if(pos==0)
 {
  head=temp->link;
  free(temp);
  return head;
 }
 for(i=0;i<pos;i++)
 {
  temp2=temp2->link;
 }
 temp2->link=temp->link;
 free(temp);
}
void print()
{
 struct node* p=head;
 printf("\n The Allocated Seats are:");
 while(p!=NULL)
 {
     printf("\t%d",p->data);
     p=p->link;
 }
}
int main()
{
    struct node* head=NULL;
    int n,i,x,ch,dh,pos,dp,dopt,de,ropt,pr;
    while(1)
    {
    printf("\n.......Railway Reservation.....");
    printf("\n1.Seat Allocation\n2.Seat Cancellation\n3.Display the allocated seats\nEnter your choice:\t");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
           printf("\n1.Allocate seats\n2.Update AllocationI\nEnter your choice:\t");
           scanf("%d",&dh);
           if(dh==1)
            {     printf("\nenter the no of passengers:");
                  scanf("%d",&n);
                  printf("\nnenter passenger id:");
                  for(i=0;i<n;i++)
                  {
                   scanf("%d",&x);
                   head=bookwithseat(x);
                  }
            }
           else if(dh==2)
            { 
                  printf("\nenter the no of seats:");
                  scanf("%d",&n);int y;
                  printf("\nenter the seat num with person id");
                  while(n>0)
                   {
                    scanf("%d %d",&x,&y);
                    bookwithid(x,y);
                    n--;
			
                   }
             }
           else
             {
                  printf("\nenter valid option");
             }
        
           break;
    case 2:
           printf("\n1.Cancel a particular seat\n2.Cancel a particular  person");
           printf("\n3.Back to MainMenu\n\nEnter your choice:");
           scanf("%d",&dopt);
           if(dopt==1)
           {
            printf("\n enter the seat no to cancel:");
            scanf("%d",&dp);
            cancelaseat(dp);
           }
           else if(dopt==2)
           {
            printf("\n enter the id no cancellation:");
            scanf("%d",&de);
            cancelanid(de);
           } 
           else
           {
            break;
           }
           break;
        
    case 3:
          printf("\nDisplay the allocated seats\n");
           print();  
          break;
    case 4:
          exit(0);
   }
   }
    return 0;
}
