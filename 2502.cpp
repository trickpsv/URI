#include <cstdio>
#include <iostream>

using namespace std;

int minusculo(char c);
int maiusculo(char c);

int main()
{
	string a , b;
	int x , y ;
	int criptografia[1000];
	
	while(	scanf("%d %d", &x , &y) == 2){
		
		for (int i = 0; i < 1000; i++)
		{
			criptografia[i] = i;
		}
		

		cin.ignore(1);
		getline(cin, a);

		getline (cin ,b);
		
		
		for(int i = 0 ; i < (int)a.size() ; i ++ )
		{
			criptografia[(int)a[i]] = maiusculo(b[i]);
			if (a[i] <= 'Z' && a[i] >='A' )
				criptografia['a'+(a[i]-'A')] = minusculo(b[i]);
			criptografia[(int)b[i]] = maiusculo(a[i]);
			if (b[i] <= 'Z' && b[i] >='A' )
				criptografia['a'+(b[i]-'A')] = minusculo(a[i]);
		}	
		
		for(int i = 0 ; i < y ; i ++)
		{
			getline(cin , a);
			string saida = "";
			for (int j = 0; j < (int)a.size(); j++)
			{
				if (  a[j] <='Z' && a[j] >= 'A')
					saida += maiusculo(criptografia[(int)a[j]]);
				else  
					saida += minusculo(criptografia[(int)a[j]]);
			}
			cout << saida << endl;
			
		}
		printf("\n");
	
	}	
	return 0;
}


int minusculo(char c)
{
	if (c <= 'Z' && c >= 'A')
		return 'a' + c-'A' ; 
	return c;
}

int maiusculo(char c)
{
	if (c <= 'z' && c >= 'a')
		return 'A' + c - 'a';
	return c;
}
