#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string,int> m ;
	int n ;
	string s;
	
	scanf("%d",&n);
	getline(cin,s);
	getline(cin,s);
	
	
	//n = n+1;
	while(n--)
	{
		int cont = 0;
		while(1)
		{
			if (!getline(cin , s))
				break;
			if (s =="\0")
				break;
			
			cont ++;
			
			if (m.find(s) != m.end())  
				m[s] +=1 ; 
			else
				m[s] = 1;
			
		}
		
		for(auto it = m.begin() ; it != m.end() ; it++)
		{
			cout << it->first ;
			printf(" %.4f\n",100*(float)it->second/(float)cont);
		}
		
		if (n != 0 )
			printf("\n");
			
		m = map<string,int>() ;
	}
	
}
