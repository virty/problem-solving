#include <stdio.h>

char str[1000], stack[1000];
int N;

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int top = -1;
		scanf("%d %s", &N, str);
		for (int i = 0; i < N; i++)
		{
			if (top == -1)
				stack[++top] = str[i];
			else if (str[i] == ')')
			{
				if (stack[top] == '(')
					top--;				
				else
					stack[++top] = str[i];
			}
			else if (str[i] == ']')
			{
				if (stack[top] == '[')
					top--;
				else
					stack[++top] = str[i];
			}
			else if (str[i] == '}')
			{
				if (stack[top] == '{')
					top--;
				else
					stack[++top] = str[i];
			}
			else if (str[i] == '>')
			{
				if (stack[top] == '<')
					top--;
				else
					stack[++top] = str[i];
			}
			else
				stack[++top] = str[i];

		}
		printf("#%d %d\n", tc, top==-1?1:0);
	}
	return 0;
}