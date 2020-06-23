#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
void admin();
void user();
//void stack();
struct store * create(struct store *);
struct store * display(struct store *);
struct store * del(struct store *);
struct store * search(struct store *);
struct store * buy(struct store *);
struct store
{
	char name[10];
	int id,no;
	struct store *next;
};
struct store *beg=NULL,*end=NULL,*k=NULL,*start=NULL,*ptr=NULL;
struct store * create(struct store *start)
{
       int i,n;
       printf("enter the number of products:\n");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
	   
		beg=(struct store*)malloc(sizeof(struct store));
		printf("\n Enter product name :");
		scanf("%s",beg->name);
		printf("\nEnter your product ID:");
		scanf("%d",&beg->id);
		printf("\nEnter your product quantity:");
		scanf("%d",&beg->no);
		beg->next=NULL;
		if(start==NULL)
                {
			start=beg;
                }
		else
		{
                  ptr=start;
                    while(ptr->next != NULL)
		    {
                          ptr=ptr->next;
                    }
                          ptr->next=beg;
                          beg->next=NULL;
		    
		}
	}

	return start;
   }



struct store *  display(struct store *start)
{
	struct store *t;
	t=start;
	while(t!=NULL)
	{ 
		printf("******************************\n");	
		printf("\nPRODUCT ID :%d\n",t->id);
		printf("NAME :%s\n",t->name);
		printf("QUANTITY:%d\n",t->no);
		printf("******************************\n");  
		t=t->next;
	}
return start;
}

struct store *  del(struct store *start )
{
	struct store *ptr,*preptr;
	int r;
	int flag=0;
        ptr=start;	
	printf("\nEnter product ID to delete:");
	scanf("%d",&r);
	if(r==ptr->id)
	{
		start=start->next;
		flag=1;
		printf("Product deleted successfully !\n");
		return start;
	}
	else
	{
		while(ptr->id!=r)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		flag=1;
		printf("Product deleted successfully !\n");
		free(ptr);
		return start;

	}
	if(flag==0)
	printf("\nProduct no. not found!!!\n");
}


struct store *  search(struct store *start)
{
	
	int r;
	int flag=0;
	printf("\nEnter the Product no:");
	scanf("%d",&r);
	struct store *t;
	t=start;
	while(t!=NULL)
	{
		if(r==t->id)
		{

			printf("******************************\n");
			printf("\nPRODUCT NO:%d\n",t->id);
			printf("\nNAME:%s\n",t->name);
			printf("\nQUANTITY:%d\n",t->no);
			printf("******************************\n");  
			flag=1;
			break;
		}
		t=t->next;
	}
	if(flag==0)
	printf("\nProduct no. not find!!\n");
return start;
}

struct store *  buy(struct store *start)
{
	
	int r,n;
	int flag=0;
	printf("\nEnter the Product no:");
	scanf("%d",&r);
	struct store *t;
	t=start;
	while(t!=NULL)
	{
		if(r==t->id)
		{
			printf("Enter Quantity of products you want to buy ?\n");
			scanf("%d",&n);
			if(t->id>=n)
			{
				t->no=t->no-n;
				printf("\n******************************\n");
				printf("\nPRODUCT NO:%d\n",t->id);
				printf("\nNAME:%s\n",t->name);
				printf("\nQUANTITY:%d\n",t->no);
				printf("******************************\n");  
				flag=1;
				break;
			}
			else
			{
				printf("\nQuantity not available\n");
				break;
			}
		}
		t=t->next;
	}
	if(flag==0)
	printf("\n Product number not find!!\n");
return start;
}

 main()
{
	int n,a;
	while(1)
	{       
                printf("****************************\n");
				printf("* GENERAL STORE MANAGEMENT  *\n");	
	            printf("****************************\n");
	         //	printf("*           *\n");
				printf("LOGIN AS :\n");
				printf("1.user \n2.Admin \n3.exit\n");
			//	printf("*************************************************\n");
				scanf("%d",&n);
				switch(n)
				{
					case 1: user();
						break;
					case 2: while(1)
						{
							printf("Enter password :");
							scanf("%d",&a);
							if(a==2424)
							{
								admin();
								break;
							}
							else
							{
								printf("\nINVALID PASSWORD\n");

							}
						}
					case 3: exit(0);

					default : printf("\nINVALID OPTION\n");
				}		
	}
}
void admin()
{
                  int ch,n;
                  while(1)
                        {
				printf("*************************************************\n");
				printf("LOGGED IN AS : ADMIN\n");
				printf("*************************************************\n");
               	 		printf("\n1-ADD A PRODUCT");
                		printf("\n2-DISPLAY ALL PRODUCTS");
                		printf("\n3-SEARCH A PRODUCT");
               			printf("\n4-DELETE A PRODUCT");
				printf("\n5-logout");
				printf("\n*************************");
               		 	printf("\nEnter your choice\n");
                		scanf("%d",&ch);
                              switch(ch)
                                       {
                                              case 1: start=create(start);
                                                         break;
                                              case 2: start=display(start);
                                                         break;
                                              case 3: start=search(start);
                                                         break;
					      case 4: start=del(start);
							 break;
                                              case 5: main();
						
					    default : printf("\n Enter number from 1-5 only \n");
                                                       
                                        }
                         }
}

void user()
       {
                  int ch,n;
                  while(1)
                        {
				printf("*************************************************\n");
				printf("LOGGED IN AS : USER\n");
				printf("*************************************************\n");
               	 		printf("\n1-BUY A PRODUCT");
                		printf("\n2-DISPLAY ALL PRODUCTS");
				printf("\n3-logout");
				printf("\n*************************");
               		 	printf("\nEnter your choice\n");
                		scanf("%d",&ch);
                              switch(ch)
                                       {
                                              case 1: start= buy(start);
						         break;
                                              case 2: start=display(start);
                                                         break;
                                              case 3: main();
						
					    default : printf("\n Enter number from 1-3 only \n");
                                                       
                                        }
                         }
        }
