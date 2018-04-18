#include <stdio.h>


void swap(char *a , char *b)// for swaping two character in the string
{
    char temp = *a;
    *a = *b;
    *b = temp ; 
}

void perm(char p[] , int start , int end ) // Main permutation function
{
    

    if(start == end)
    {
        printf("%s\n",p);
    }
    else{
        
        for(int i = start ; i < end ; i++)
        {
         
            swap(p+start , p+i); 
            
            perm(p , start+1 , end);
         
            swap(p+start , p+i );
        }
    }
   
   

}
int main()
{
   
   char string[1000];
   int sindex = 0 , lindex ;
   
   
   
   scanf("%s",string);
   lindex = strlen(string);
  
   perm(string , sindex , lindex);
 
    return 0;
}
