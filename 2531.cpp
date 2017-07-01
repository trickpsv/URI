#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 9999999
#define INFNEG -9999999


using namespace std;

int tree[300010][2];
int vet[100010];
int folhas[100010];

typedef vector<int> vi ;



void build(int no , int a , int b )
{
	if (a > b) return ;
	
	if (a == b){
		tree[no][0] = vet[a];
		tree[no][1] = vet[a];
		folhas[a] = no ;
		return ;
	}
	
	build( no << 1 , a , (a+b)>>1);
	build( (no << 1) + 1 , ((a + b)>>1) +1 , b);
	
	tree[no][0] = min(tree[no<<1][0],tree[(no<<1) +1][0]);
	tree[no][1] = max(tree[no<<1][1],tree[(no<<1) +1][1]);	
	
}

void att(int no)
{
	if (no == 0) return ;
	
	tree[no][0] = min(tree[no<<1][0],tree[(no<<1)+1][0]);
	tree[no][1] = max(tree[no<<1][1],tree[(no<<1)+1][1]);
	
	if (no != 1) att(no>>1);
}


pair<int,int> query(int no , int a , int b , int i , int j)
{
	if (a > b || a > j || b < i)
		return make_pair(INF,INFNEG);
	if (i <= a && b <= j)
		return make_pair(tree[no][0],tree[no][1]);
	
	pair<int,int> p1 = query((no << 1)    ,      a         , (a+b)>>1, i , j );
	pair<int,int> p2 = query((no << 1) + 1, ((a+b)>>1) + 1 ,     b   , i , j);
	
	return make_pair(min(p1.first,p2.first),max(p1.second,p2.second));
		
}



int main()
{
	int n;
	int  x , y , aux , q;
	pair<int , int> par ;
	int cont = 0;
	
	while(scanf("%d",&n) == 1)
	{
		//if (cont != 0) printf("\n");
		//cont ++;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&vet[i]);
		}
		
		build(1, 0, n-1 );
		
		scanf("%d",&q);
		
		for(int i = 0 ; i < q ; i ++)
		{
			scanf("%d %d %d", &aux , &x , &y);
			if (aux == 1)
			{
				tree[folhas[x-1]][0] = y;
				tree[folhas[x-1]][1] = y;
				att(folhas[x-1]>>1);
				
			}
			else
			{
				par = query(1,0,n-1,x-1,y-1);
				printf("%d\n",par.second-par.first);
			}
		}
		
		
	}
	
	
}
