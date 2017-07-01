#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

char complementar(char c)
{
	if (c =='C')
		return 'F';
	if (c =='F')
		return 'C';
	if (c =='S')
		return 'B';
	return 'S';
}

int main()
{
	string s;
	stack<char> p =  stack<char>();	
	int i , cont;
	
	while( (cin >> s))
	{
		cont = 0 ;
		int tam = s.size();
		
		for (i = 0 ; i < tam ; i ++)
		{
			if (p.empty())
				p.push(s[i]);
			else if(p.top() == complementar(s[i]))
			{
				cont ++;
				p.pop();
			}
			else
			{
				p.push(s[i]);
			}
		}
		
		printf("%d\n",cont);
		p =  stack<char>();
	}
}
