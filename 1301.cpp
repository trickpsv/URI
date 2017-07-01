#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int tree[300005];
int Vetor[300005];
int Folhas[300005];

void criar(int no, int a, int b)
{
	if(a>b) 
		return;
	if(a==b)
	{
		if (Vetor[a] > 0)
			tree[no] = 1 ;
		else if (Vetor[a] == 0)
			tree[no] = 0;
		else 
			tree[no] = -1 ;
		
		Folhas[a] = no;
		return;
	}
 
	criar(no<<1, a, (a+b)>>1);
	criar(1 + (no<<1), 1 + ((a+b)>>1), b);
	tree[no] = tree[no<<1] * tree[1 + (no<<1)];
}

void C(int no)
{
	if(no == 0)
		return ;
    tree[no] = tree[no<<1] * tree[(no<<1)+1];
    if(no != 1)
		C(no>>1);
}

int P(int no, int a, int b, int i, int j)
{
	if(a>b || a>j || b<i) 
		return 1;
	if(i<=a && b<=j) 
		return tree[no];
		
	int V1 = P(no<<1, a, (a+b)>>1, i, j);
	int V2 = P(1 + (no<<1), 1 + ((a+b)>>1), b, i, j);
	return V1*V2;
}

int n;
int main()
{
	int m,x,y;
	char c;
	int i, Temp;

	while(scanf("%d %d\n",&n,&m)==2)
	{
		memset(Vetor, 0 , sizeof(Vetor));
		memset(tree , 0 , sizeof(tree) );
		memset(Folhas , 0 , sizeof(Folhas));
		
		for(i = 0 ; i < n ; i++)
			scanf("%d",&Vetor[i]);
					
		criar(1, 0, n-1);
		
		for(i = 0 ; i < m ; i++)
		{
			cin >> c >> x >> y ;
		
			if(c == 'P')
			{
				Temp = P(1,0,n-1,x-1,y-1);
				
				if(Temp == 0)
					printf("0");
				else if(Temp < 0)
					printf("-");
				else
					printf("+");
			}
			else
			{
				if (y > 0)
					tree[Folhas[x-1]] = 1;
				else if (y == 0)
					tree[Folhas[x-1]] = 0;
				else
					tree[Folhas[x-1]] = -1;
				C(Folhas[x-1]>>1);
			}
		}
		printf("\n");
	}

    return 0;
}
