#include <stdio.h>

int main()
{
    char input;
    int arr[10000]={0};
    int index=0;
    input = '7';
    
    printf("Postfix expression: S (example:  3 4 8 6 * + * 5 +  )\n(Note: please use single digit for number).\n");
    printf("Enter postfix expression : ");
    while(1 && input != '\n')
    {
        scanf("%c",&input);
        if(input > '9' || input < '0')
        {
                if(input == '*')
                {
                    index-=2;
                    
                    arr[index] = arr[index+1]*arr[index];
                    index++;
                }
                else
                if(input == '+')
                {
                    index-=2;
                    
                    arr[index] = arr[index+1]+arr[index];
                    index++;
                }
                else
                if(input == '-')
                {
                    index-=2;
                    
                    arr[index] = arr[index+1]-arr[index];
                    index++;
                    
                }
                else
                if(input == '/')
                {
                    index-=2;
                    
                    arr[index] = arr[index+1]/arr[index];
                    index++;
                }
        }
        else
        {
            arr[index++] = input - '0';
        }
        
    }
    printf("The Postfix expression value is = %d\n",arr[0]);
    return 0;
}
