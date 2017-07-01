#include <cstdio>
#include <queue>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> s = queue<int>();
	int n , x ;
	while(cin >> n , (n | 0)){
		for(int i = 1 ; i <= n ; i ++)
		{
			s.push(i);
		}
		
		printf("Discarded cards: ");
		while(s.size() > 1)
		{
			x = s.front();
			if(s.size() >= 2 && (int)s.size() < n) printf(", ");
			printf("%d",x);
			
			s.pop();
			
			s.push(s.front());
			s.pop();	
		}
		printf("\n");
		
		printf("Remaining card: %d\n",s.front());
		
		s = queue<int>();
	}	
	
	return 0 ;
}
