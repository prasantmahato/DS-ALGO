#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Type for individual stack entry
struct stack_entry {
	char *data;
  	struct stack_entry *next;
};

// Stack structure
struct stack_t
{
	struct stack_entry *head;
	size_t stackSize;  
};

// Create new stack instance
struct stack_t *newStack(void)
{
	struct stack_t *stack = malloc(sizeof *stack);
	if (stack)
	{
		stack->head = NULL;
		stack->stackSize = 0;
	}
	return stack;
}

/**
 * Make a copy of the string to be stored (assumes  
 * strdup() or similar functionality is not
 * available
 */
char *copyString(char *str)
{
	char *tmp = malloc(strlen(str) + 1);
	if (tmp)
		strcpy(tmp, str);
	return tmp;
}

//  Push a value onto the stack
void push(struct stack_t *theStack, char *value)
{
	struct stack_entry *entry = malloc(sizeof *entry); 
	if (entry)
	{
		entry->data = copyString(value);
		entry->next = theStack->head;
		theStack->head = entry;
		theStack->stackSize++;
	}
}


//Get the value at the top of the stack
char *top(struct stack_t *theStack)
{
	if (theStack && theStack->head)
		return theStack->head->data;
	else
		return NULL;
}

/*
 * Pop the top element from the stack; this deletes both 
 * the stack entry and the string it points to
 */
void pop(struct stack_t *theStack)
{
	if (theStack->head != NULL)
	{
		struct stack_entry *tmp = theStack->head;
		theStack->head = theStack->head->next;
		free(tmp->data);
		free(tmp);
		theStack->stackSize--;
	}
}


// Clear all elements from the stack
void clear (struct stack_t *theStack)
{
	while (theStack->head != NULL)
		pop(theStack);
}


// Destroy a stack instance
void destroyStack(struct stack_t **theStack)
{
	clear(*theStack);
	free(*theStack);
	*theStack = NULL;
}

// Check for valid operator
int isOperator(char ch)
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Postfix expression to prefix 
static void post_to_pre(struct stack_t *theStack,char *str)
{
    int l = strlen(str);

    char p[SIZE];
    char op1[SIZE];
    char op2[SIZE];

    for(int i=0; i<l; i++)
    {
		char curr[2] = {str[i],'\0'};
		char *st = copyString(curr);
	
		if(isOperator(str[i]))
		{
			// Add operator in P
			strcpy(p,st);
			
			// Add stack[top] in op1 
			strcpy(op1,top(theStack));
			pop(theStack);
			
			// Add stack[top-1] in op2 
			strcpy(op2,top(theStack));
			pop(theStack);
			
			// Join p = p + op2 + op1
			strcat(p,op2);
			strcat(p,op1);
			
			// Push P back to the stack
			push(theStack,p);
		}
		else    
            push(theStack,st);	// Directly push the operand
    }
	// The top element is the Prefix expression
    printf("\nPrefix Expression:: %s\n",top(theStack));
}


int main()
{
    struct stack_t *theStack = newStack();
    char data[SIZE];
    printf("\nEnter a POSTFIX expression :: ");
    scanf("%s",data);
    
    post_to_pre(theStack,data);

    destroyStack(&theStack);
    return 0;
}