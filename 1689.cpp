#include <cstdio>
#include <cstring> 
#include <algorithm>
#define MAX 1000010

using namespace std;

int pos[MAX];
int lucro[MAX];
int vet[MAX];
int sol[MAX];

int main()
{
	int t, n , k;
	
	int limite = 1000000;
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d",&n,&k);
		
		memset(vet , 0 , sizeof(vet));
		memset(vet , 0 , sizeof(sol));
		
		for (int i = 1 ; i <= n ; i ++)
		{
			scanf("%d", &pos[i]);
		}
		for (int i = 1 ; i <= n ; i ++)
		{
			scanf("%d", &lucro[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (lucro[i] >vet[pos[i]] )
				vet[pos[i]] = lucro[i] ;
		}
		
		limite = pos[n];
		
		//printf("limite %d --",limite);
		
		sol[1] = vet[1];
		for (int i = 2; i <= limite; i++)
		{
			
			sol[i] = sol[i-1];
			if (vet[i] != 0)
			{
				if (i > k)
					sol[i] = max(sol[i] , sol[i-k] + vet[i]); 
				else
				{
					sol[i] = max(sol[i-1] , vet[i]);
				}
			}
			
		}
		

		
		
		printf("%d\n",sol[limite]);
		
				
	
	}
	
}
