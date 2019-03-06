#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#define listsize 5


typedef struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL 
    struct Node* prev; // Pointer to previous node in DLL 
} node;
node *head = NULL;
node *tail = NULL;

node * create(int data){

   node *pNew=(node *) malloc(1*sizeof(node));
   pNew->data=data;
   pNew->prev=pNew->next=NULL;
   return pNew;
}

void add(node  *pNode){

if(head==NULL){
  head=tail=pNode;
}
else{
tail->next=pNode;
pNode->prev=tail;
tail=pNode;
}

}

void printList(node* nodes) 
{  
    printf("\nTraversal in forward direction \n"); 
    while (nodes != NULL) { 
        printf(" %d ", nodes->data); 
        nodes = nodes->next; 
    }
   
  
}
void deleteNode(int position) 
{ 
  node *temp1=head;
  node *temp2;
  int i;
  if(position==1){
    head=temp1->next;
    free(temp1);
    return;

  }
  for(i=0;i<position-2;i++){

    temp1=temp1->next;

   }
 temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
   
}
void insertNode(int data,int position){
   node* temp1;
   node* temp2;
   int i;
   temp1=create(data);
   temp1->data=data;
   temp1->next=NULL;
   if(position==1){
    temp1->next=head;
    head=temp1;
    return;
   }
   temp2=head;
   for(i=0;i<position-2;i++){
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
  




}  





int main(){

char menu[5][10]={"create","display","delete","insert","exit"};
int flag=1;
int pos=0;
int i;
char ch;
int number,delete,position,insert;
node *newNode;

do{
  clrscr();
  for(i=0;i<listsize;i++){
  if(i==pos){
	 textattr(0x70);
	 }
	 gotoxy(5,5+i);
	 cprintf("%s",menu[i]);
	 textattr(0x07);

  }
  ch=getch();

  switch(ch){
	 case NULL:
		ch=getch();
		switch(ch){
		   case 80:
		   {pos++;
		   if(pos>=listsize)
			  pos=0;}
		   break;

		   case 72:
		   {pos--;
		   if(pos<0)
			 pos=listsize-1;}
		   break;

		   case 71:
			  pos=0;
		   break;

		   case 79:
			  pos=listsize-1;
		   break;

		}
	 break;

	 case 13:
	   clrscr();
	   printf("%s",menu[pos]);
           if(pos==0){
             printf("Enter Your Number: ");
             scanf("%d",&number);
             newNode=create(number);
             add(newNode);
              }
           if(pos==1){
               
               printList(head);

              }
           if(pos==2){
            printf("Enter Your Number: ");
             scanf("%d",&delete);
             deleteNode(delete);
             printf("\n");
             printList(head);
        

             }


             if(pos==3){
            printf("Enter Your data: ");
             scanf("%d",&insert);
            printf("Enter Your postion: ");
              scanf("%d",&position);
             insertNode(insert,position);
             printf("\n");
             printList(head);
        

             }
              
              
	   if(pos==listsize-1)
		   flag=0;
	   getch();
	 break;
	 case 27:
	   flag=0;
	 break;



  }








}while(flag==1);








  getch();
 return 0;
}