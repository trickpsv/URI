#include <cstdio>
#include <stack>
#include <iostream>
#define MAX 1010

using namespace std;

int main()
{
	int n ;
	int i;
	int vet[MAX];
	stack<int> entrada  ;
	stack<int> posto    ;
	
	
		
	while( 1 )
	{
		scanf("%d",&n);
		if (n == 0) break ;
		
		scanf("%d",&vet[0]);
		while(vet[0] != 0)
		{
			for (i = 0 ; i < n ; i ++)
			{
				entrada.push(n-i);				
			}
			for(i = 1 ; i < n ; i ++) 
			{
				scanf("%d",&vet[i]); 
			}
			int erro = 0;		
			for (i = 0 ; i < n ; i ++) 
			{
				while(!entrada.empty() && (entrada.top() <= vet[i] ) )
				{
					posto.push(entrada.top());
					entrada.pop();	
				}
				
				if(!posto.empty() && posto.top() != vet[i]) 
				{
					printf("No\n");
					erro = 1;
					break;
				}	
				else
				{
					posto.pop();
				}
			}
			if( !erro)
				printf("Yes\n");
			erro = 0 ;
			
			entrada = stack<int>();
			posto = stack<int>();
			scanf("%d",&vet[0]);
			
			
		}
		printf("\n");
		
	}
	
	return 0;
}
