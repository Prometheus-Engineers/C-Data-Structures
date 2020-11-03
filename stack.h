typedef struct {
	int top;
	int limit;
	int* list;
} Stack;

Stack create_stack(int limit);
void print_stack(Stack stack);
int stack_push(Stack *stack, int num);
int stack_pop(Stack *stack);

Stack create_stack(int limit)
{
	Stack stack;
	stack.top = 0;
	stack.limit = limit;
	stack.list = (int *)malloc(limit * sizeof(int));
	return stack;
}

void print_stack(Stack stack)
{
	printf("[");
	while(stack.top > 0)
		printf(" %d,", stack_pop(&stack));
	puts(" ]");
}

int stack_push(Stack *stack, int num)
{
	if (stack->top == stack->limit)
	{
		puts("Stack overflow");
		return -1;
	}
	stack->list[stack->top++] = num;
	return 0;
}

int stack_pop(Stack *stack)
{
	if (stack->top == 0)
	{
		puts("Stack underflow");
		return - 1;
	}
	int num = stack->list[stack->top];
	stack->list[stack->top--] = 0;
	return num;
}
