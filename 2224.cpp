#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int x[20];
int y[20];
int n;
float memo[1<<17];

float d(int i , int j);
float dp(int bitmask);

int main()
{
	int t ; 
	
	scanf("%d",&t);
	
	while(t--)
	{
		for (int i = 0; i < 1<<16; i++)
		{
			memo[i] = -1.0;
		}
		
		scanf("%d",&n);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d",&x[i],&y[i]);
		}
		
		printf("%.2f\n",dp(0));
		
	}
	
	return 0;
}

float d(int i , int j)
{
	
	return hypot((float)x[i] - (float)x[j],(float)y[i] - (float)y[j]) ;
}

float dp(int bitmask)
{
	if (memo[bitmask] > -0.5)
		return memo[bitmask];
	if(bitmask == (1<<n)-1)
		return memo[bitmask]=0;

	float ans = 9999999999.;
	int p1 , p2;
	
	for(p1 = 0 ; p1 < n  ; p1++)
		if ( !( (1 << p1) & bitmask ) )
			break;
		
	for(p2 = p1+1 ; p2 < n ;p2++ )
		if ( !(( 1 << p2 ) & bitmask) )
			ans = min(ans, dp(bitmask | 1<<p1 | 1<<p2)+d(p1,p2));
	
	return memo[bitmask] = ans;
}
