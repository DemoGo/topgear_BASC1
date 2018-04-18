#include <stdio.h>
#define primeN 7;

typedef long long int lli;

struct node {
    lli ecode;
    char eaddr[200];
    struct node *next;
};



int hashFunction(lli code)
{
    
    return code%primeN;
    
}



void insertHash(struct node *arr[] , lli code , char addr[])
{
    
    int index = hashFunction(code);
    
    int i;
    
    if(arr[index] == NULL)
    {
    
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        arr[index] = temp;
        temp->ecode = code;
        strcpy(temp->eaddr , addr);
        temp->next = NULL;
    }
    else
    {
        struct node *tmp;
                
        tmp = arr[index];
        
        int check = 1;
        
        if(tmp->ecode == code)
        {
            printf("***ALERT***\n");
            printf("Employee with same code already exist \n");
            check = 0;
          
        }
        
        
        while(tmp->next != NULL)
        {
            
            if(tmp->ecode == code)
            {
                printf("***ALERT***\n");
                printf("Employee with same code already exist \n");
                check = 0;
                break;
            }
            tmp = tmp->next;
        }
        
        if(check)
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            tmp->next = temp;
            temp->ecode = code;
            strcpy(temp->eaddr , addr);
            temp->next = NULL;
        }
      
    }
    
}







void updateHash(struct node *arr[] , lli code) //Update hashMap by using code
{
    int index = hashFunction(code);
    
    int i,check=1;
    
    if(arr[index] == NULL)
    {
        printf("Emoloyee with this code NOT exist\n");
    }
    else
    {
        struct node *tmp;
        char addr[200];
        tmp = arr[index];
        
        while(tmp->next != NULL)
        {
            if(tmp->ecode == code)
            {
                printf("Employee old Address : %s\n",tmp->eaddr);
                printf("Enter New Address : ");
                scanf(" ");
                gets(addr);
                
                strcpy(tmp->eaddr , addr);
                
                check = 0;
                break;
            }
            tmp = tmp->next;
            
        }
        if(check && tmp->ecode == code)
        {
                printf("Employee old Address : %s\n",tmp->eaddr);
                printf("Enter New Address : ");
                scanf(" ");
                gets(addr);
                
                strcpy(tmp->eaddr , addr);
                
                check = 0;
                
            
        }
        
        
        
        if(check)
        {
             printf("Emoloyee with this code NOT exist\n");
        }
    }
    
    
}


void deleteHash(struct node *arr[] , lli code)
{
    int index = hashFunction(code);
    
    int i,check=1;
    
    if(arr[index] == NULL)
    {
        printf("Emoloyee with this code NOT exist\n");
    }
    else
    {
        struct node *tmp;
        tmp = arr[index];
        
        if(tmp->ecode == code)
        {
            arr[index] = arr[index]->next;
            check = 0;
        }
        else
        {
                  
            while(tmp->next != NULL)
            {
                if(tmp->next->ecode != code)
                {
                    struct node *tp ;
                    tp = tmp->next;
                    
                    tmp->next = tmp->next->next;
                    check = 0;        
                    break;
                }
                tmp = tmp->next;
            }
            
            
        }
        if(check)
        {
             printf("Emoloyee with this code NOT exist\n");
        }
    }
    
}


int main()
{
     int opt,i;
    lli code;
    char addr[200];
    struct node *arr[7];
    
    for(i=0 ; i<7 ; i++)
    {
        arr[i]=NULL;
    }
    
    while(1)
    {
        printf("******************MENU*****************\n");
        printf("Enter 1 for INSERT Employee Information\n");
        printf("Enter 2 for UPDATE Employee Information\n");
        printf("Enter 3 for DELETE Employee Information\n");
        printf("Enter 4 for STOP operation\n");
        printf("******************MENU*****************\n");
        
        printf("Enter your choice : ");
        
        
       
        scanf("%d",&opt);
        
        switch(opt)
        {
            case 1: 
                    printf("Enter Employee code(in Numbers) : ");
                    scanf("%lld",&code);
                    printf("Enter Employee Address : ");
                    scanf(" ");
                    gets(addr);                
                    
                    insertHash(arr,code,addr);
                    
                    break;
        
            case 2: printf("Enter Employee code(in Numbers) whose Info you want to UPDATE : ");
                    scanf("%lld",&code);
                    
                    updateHash(arr,code);
                    break;
                    
            case 3: printf("Enter Employee code(in Numbers) whose Info you want to DELETE : ");
                    scanf("%lld",&code);
                    deleteHash(arr,code);
                    break;
                    
                    
                    
            case 4: return 0;
                    break;
                   
            
            default : printf("Please Enter valid Input\n");
        }
    }
    
    
    return 0;
}
