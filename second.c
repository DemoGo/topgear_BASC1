#include <stdio.h>

void printOutput(int a[] , int n)
{
    printf("\nNumber in the array : ");
    
    int max = -10000, min = 100000;
    
    int total = 0;
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",a[i]);
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
        total += a[i];
    }
    printf("\n");
    
    printf("Number of elements in the array : %d\n",n);
    printf("Sum of elements of the aaray : %d\n",total);
    printf("Average of all elements of the array = %f\n", ((float)total)/((float)n));
    printf("The lagest number of the array : %d\n",max);
    printf("The smallest number of the array : %d\n",min);
    
    
}

int main()
{
    char string[100];
    int arr[2000]={0};
    int index = 0,i;
    while(1)
    {
        
        printf("Enter Number : \n*type quit for exit : \n-> : ");
        scanf("%s",string);
        int n = strlen(string);
        
        if(strcmp(string , "quit") == 0 || strcmp(string , "QUIT") == 0 || strcmp(string , "Quit") == 0)
        {
            printOutput(arr , index);
            return 0;
            
        }
        else
        {
        
            int num=0;
            
            for(i=0 ; i<n ; i++)
            {
                if(string[i] < '0' || string[i] > '9')
                {
                    printf("Please enter valid input : \n");
                    break;
                }
                num = num*10 + string[i]-'0';
            }
            
            
            if(i>=n)
            {
                arr[index++] = num;
            }
        }
    }
    return 0;
}
