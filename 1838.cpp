#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define MAX 1010

using namespace std;

//bool verif[MAX][3610][3610];
map < pair < int, pair < int,int > > , int> memo ;

int ini[MAX];
int fim[MAX];

int dp(int i , int j , int k , int n);


int main()
{
	int n ;
	int i; 
	scanf ("%d",&n);
	
	memo  = map<pair<int,pair<int,int>>,int>();
	
	for (i = 0 ; i < n ; i ++)
	{
		scanf("%d %d", &ini[i] , &fim[i]);
	}
	
	printf("%d\n",dp(0 , 0 , 3600,n));
	
	return 0 ;
}

int dp(int i , int j , int k , int n)
{
	//caso eu já tenha calculado o estado atual
	if (memo.find(make_pair(i,make_pair(j,k))) != memo.end() )
		return memo[make_pair(i,make_pair(j,k))];
	// caso eu tenha olhado todos os horários
	if (i == n)
		return 0;
	// caso você queira calcular um horário de duração 0 , a resposta é 0 
	if ( j == k)
		return 0;
	// não consigo usar o horario(i)
	if ( j > ini[i] || k < fim[i] )
		return dp( i+1 ,  j ,  k , n);
	
	// a resposta pra um estado é o melhor entre não pegar aquele horario e pegar aquele horario
	// caso você pegue aquele horário voce precisa calcular o melhor pros horarios que sobraram 
	int ans;
	ans = max( dp(i+1,j,k,n) , dp(i+1,j,ini[i],n) + dp(i+1,fim[i],k,n) + fim[i] - ini[i] );
	memo[make_pair(i,make_pair(j,k))] = ans;
	return ans; 
}
