#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10010

using namespace std;

int vet[MAX];
int sol[2][MAX][MAX];
int usado[2][MAX][MAX];

int dp(int i , int j , int pessoa);

int main()
{
	int n;
	
	
	
	while(scanf("%d",&n) == 1)
	{
		//memset(usado,0,sizeof(usado));
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&vet[i]);
		}
		printf("%d\n",dp(0,n-1,0));
		
	}
	
	return 0;
}

int dp(int i , int j , int pessoa)
{
	//printf("%d %d\n",i,j);
	if (usado [pessoa][i][j] != 0)
		return sol[pessoa][i][j];
	//printf("medo\n");
	if (i == j )
	{
		printf("%d - \n",vet[i]);
		return vet[i];

	}
	else 
	{
		if (pessoa == 0 )
		{
			sol[pessoa][i][j] = max(dp(i+1,j,1) + vet[i], dp(i,j-1,1) + vet[j]);
			usado[pessoa][i][j] = 1;
			return sol[pessoa][i][j];
		}
		else
		{
			sol[pessoa][i][j] = min(dp(i+1,j,0) , dp(i,j-1,0));
			usado[pessoa][i][j] = 1;
			return sol[pessoa][i][j];		
		}
	}
	
}
