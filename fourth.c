#include <stdio.h>


int order(char operand)
{
    switch(operand)
    {
        case '^' : return 3;
  
        case '*':  return 2;
  
        case '/':  return 2;
  
        case '+':  return 1;
  
        case '-':  return 1;
  
        default : return 0;
    }
    return 0;
}


void operatorFunction(char input , char stck[] , int *si , char output[] , int *oi)
{
    if( (*si) == 0 || order(input) > order(stck[(*si)-1])) //checking stack is empty or the current operator precedence is higher than stack top element
    {
        stck[(*si)] = input;
        
        (*si)++;
        
    }
    else
    {
        if(input == '(')
        {

            stck[(*si)] = input;
            (*si)++;

        }
        else if(input == ')')
        {
            (*si)--;
            while(stck[*si] != '(')
            {
                output[(*oi)++] = stck[(*si)--];
            }

        }
        else
        {

            while( (*si) !=0 && order(input) <= order(stck[(*si)-1]) )
            {
                (*si)--;
                output[(*oi)++] = stck[(*si)];
                
            }
            
            stck[(*si)++] = input;
        }
        
    }
}

void infixToPostfix(char input[], char output[] , char stck[])
{
    
    int i=0,j=0;
    int oi=0,si=0;
    
    int len = strlen(input);
    
    for(i=0 ; i<len ; i++)
    {
        if(input[i]!='+' && input[i]!='-' && input[i]!='*' && input[i]!='/' && input[i]!='^' && input[i] != '(' && input[i] != ')')//other than operators
        {

            output[oi++] = input[i];
        }
        else // operators
        {
            operatorFunction(input[i],stck, &si , output , &oi);
        }
    }
    si--;
    if(si!=-1)
    {
        while(si!=-1)
        {
            output[oi++] = stck[si--];
        }
    }
    output[oi]='\0';
   
}

void strReverse(char input[], char input2[])
{
    int i=0;
        
    int len = strlen(input);
    int j=0;
    i=len-1;
    
    while(i>=0)
    {
        if(input[i] == '(')
        {
            input2[j++]=')';
            i--;
        }
        else if(input[i] == ')')
        {
            input2[j++]='(';
            i--;
        }
        else
        {
            input2[j++]= input[i--];
        }
    }
    input2[j]='\0';
    
}

int main()
{
    char input[1000];
    char output[1005],stck[1000];
    int choice;
    printf("*** ENTER 1 for INFIX to POSTFIX ***\n");
    printf("*** ENTER 2 for INFIX to PRIFIX  ***\n");
    printf("Enter your Choice : ");
    scanf("%d",&choice);
    printf("Enter INFIX expression : ");
        
    scanf("%s",input);
    
    if(choice == 1)
    {
        
        infixToPostfix(input,output,stck);
        printf("The POSTFIX expression is %s for %s\n",output,input);
        
    }
    else if(choice == 2)
    {
        
        char input2[1005];
        
        strReverse(input,input2);
        
        
        infixToPostfix(input2,output,stck);
        strReverse(output,input2);
        printf("The PRIFIX expression is %s for %s\n",input2,input);
    }
    return 0;
}
