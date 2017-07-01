#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int vet[10010][65];
int aux[65];

int un(int x , int y);
int in(int x , int y);

int main()
{
	int T ;
	int n;
	int q ;
	int m;
	int c , x , y ;
	
	scanf("%d",&T);
	
	while(T--)
	{
		
		scanf("%d",&n);
		
		memset(vet , 0 , n*65*sizeof(int));
		
		
		for (int i = 0; i < n ; i++)
		{
			scanf("%d",&m);
			for (int j = 0; j < m; j++)
			{
				int ajd;
				scanf("%d",&ajd);
				vet[i][ajd] = 1;
			}
		}
		
		scanf("%d",&q);
		for(int i = 0 ; i < q ; i ++)
		{
			scanf("%d %d %d",&c,&x,&y);
			printf("%d\n",c==1?(in(x-1,y-1)):(un(x-1,y-1)));
		}
		
	}
	
	return 0;
}

int in(int x, int y)
{
	int soma = 0;
	for (int i = 1; i <= 60; i++)
	{
		soma+= min(vet[x][i] , vet[y][i]);	
	}
	return soma;
}

int un(int x , int y)
{
	int soma = 0;
	for (int i = 1; i <= 60; i++)
	{
		soma+= max(vet[x][i] , vet[y][i]);	
	}	
	return soma;
}

