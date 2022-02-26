#include<stdio.h>
#include<string.h>

char infix[20],prefix[20],postfix[20]; 
void infix_to_postfix();
void infix_to_prefix();                 

char stack[20];
int top=-1;

void push(int index)            
{
top++;
stack[top] = infix[index];
}

char pop()
{
char ch;
ch = stack[top];
stack[top] = '\0';
top--;
return(ch);
}

////

int precedence(char alpha ) 
{
	
if(alpha == '+' || alpha =='-')
{
return(1);
}
if(alpha == '*' || alpha =='/')
{
return(2);
}
return 0;
}

int main()
{
printf("\nINPUT THE INFIX EXPRESSION : ");
scanf("%s",infix);
infix_to_prefix();
printf("\n");
infix_to_postfix();
return 0;
}

////  


void infix_to_prefix()
{
   int i = 0,j = 0;
   strrev(infix); 
while(infix[i] != '\0')
{
  
    if(infix[i] >= 'a' && infix[i] <= 'z')
    { 
     prefix[j] = infix[i];
     j++;
     i++;
    }
   
    else if(infix[i] == ')')
    {
     push(i);
     i++;
    }

   else if(infix[i] == '(') 
{
       while(stack[top] != ')') /* pop till opening bracket is found */
        {
          prefix[j] = pop();
          j++;
        }
        pop();
        i++;    
}

  else
  {
  if( precedence(infix[i]) <= precedence(stack[top]))
    {
 
         while(precedence(stack[top]) >= precedence(infix[i]))
	     {
          prefix[j] = pop();    // Pop the operator
          j++;
          if(top < 0) 
      	  {
          break;
          }
	}
          push(i);
          i++;
        }
     
  else
   {
     push(i);  
     i++;
    }
   }
}


while(top != -1)
{
prefix[j] = pop();
j++;
}


strrev(prefix);
strrev(infix);
prefix[j] = '\0';
printf("EQUIVALENT PREFIX NOTATION : %s ",prefix);
}

////

void infix_to_postfix()
{
   int i =0,j = 0;         
while(infix[i] != '\0')               //(a+c-e*b)-(c*d)'\0'
{
  
    if(infix[i] >= 'a' && infix[i] <= 'z')
    { 
     postfix[j] = infix[i];
     j++;
     i++;
    }
   
    else if(infix[i] == '(')
    {
     push(i);
     i++;
    }

   else if(infix[i] == ')') 
   {
       while(stack[top] != '(') /* pop till opening bracket is found */
        {
          postfix[j] = pop();
          j++;
        }
        pop();
        i++;
     
}

  else
  {
  if( precedence(infix[i]) <= precedence(stack[top]))                  //a+b/c
    {
 
         while(precedence(stack[top]) >= precedence(infix[i]))
	     {
          postfix[j] = pop();    // Pop the operator
          j++;
          if(top < 0) 
      	  {
          break;
          }
	}
          push(i);
          i++;
        }
     
  else
   {
     push(i);  
     i++;
    }
   }
}


while(top != -1)
{
postfix[j] = pop();
j++;
}



postfix[j] = '\0';
printf("EQUIVALENT postfix NOTATION : %s ",postfix);
}


