#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string , float> dic ; 
	int n , m , p  , quantidade;
	string fruta;
	float preco;
	float total;
	
	cin >> n;
	
	for(int i = 0 ;  i < n ; i ++)
	{

		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> fruta >> preco ;
			dic[fruta] = preco ; 
		}
		cin >> p ;
		
		total = 0 ;
		for (int j = 0; j < p; j++)
		{
			cin >> fruta >> quantidade ;
			total += dic[fruta]*quantidade ;
		}
		
		printf("R$ %.2f\n",total);
		dic = map<string , float>();		
	}
	
	return 0 ; 
}
