#include<bits/stdc++.h>
using namespace std;
struct node
{
	int i;
	int j;
	int query;	
	struct node* left;
	struct node* right;
};
static bool min_freq(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}
void print_map(map<int,int> m)
{
	map<int,int>::iterator it;
	printf("[ ");
	for( it = m.begin(); it != m.end(); it ++ )
	{
		printf("%d:%d ",it->first,it->second);
	}
	printf(" ]\n");
}
map<int,int> query(int i,int A[])
{
	map<int,int> rquery;
	rquery.insert(make_pair(A[i],1));
	return rquery;
}
map<int,int> compare_queries(map<int,int> m1, map<int,int> m2)
{
	map <int,int> rquery;
	rquery = m2;	
	map<int,int>::iterator it,it2;
	for ( it = m1.begin(); it != m1.end(); it ++ )
	{
		it2 = rquery.find(it->first);
		if(it2 != rquery.end())
		{
			it2 -> second += it -> second;
		}
		else
		{
			rquery.insert(make_pair(it->first,it->second));
		}
	}
	return rquery;
}
map<int,int> createSegmentTree(struct node *root,int A[])
{
	map<int,int> left_query,right_query;
	map<int,int> rquery;
	int pivot;
	//cout << "yes";
	if(root ->  i ==  root -> j)
	{
		//cout << "bacha";
		root -> left = NULL;
		root -> right  = NULL;
		rquery = query(root -> i, A);
		//printf("[%d,%d] : ", root -> i, root -> j );
		//print_map(rquery);
		//printf("[%d,%d] : %d\n",root -> i,root -> j,rquery);
		return rquery;
	}
	//cout <<"em pori etlunnav";
	pivot = (root->i + root->j ) / 2;
	//cout << "yes";
	root -> left = (struct node * ) malloc (sizeof(struct node));
	//cout << "yes";
	root -> left -> i = root -> i;
	root -> left -> j =  pivot;
	root -> right = (struct node *) malloc ( sizeof (struct node));
	root -> right -> i = pivot + 1;
	root -> right -> j = root -> j;
	left_query = createSegmentTree(root -> left,A);
	right_query = createSegmentTree(root -> right,A);
	rquery = compare_queries(left_query,right_query);
	//printf("[%d,%d] : ",root -> i, root -> j);
	//print_map(rquery);
	//printf("[%d,%d] : %d\n",root -> i,root ->j,rquery);
	return rquery;
}
map<int,int> dynamic_query(int a[],struct node* root, int left, int right)
{
	int pivot;
	map<int,int>::iterator return_query_pair;
	map<int,int> return_query;
	pivot = (root -> i + root -> j) /2;
	//printf("[%d,%d] ",root->i,root ->j );
	if( left == right )
	{
		//printf("[%d:%d]\n",left,right);
		return query(left,a);
	}
	if(left <= pivot && right <= pivot)
	{
		//printf("[%d:%d]\n",left,right);
		return_query = dynamic_query(a,root -> left,left,right);
	} 
	else if ( left > pivot && right > pivot )
	{
		//printf("[%d:%d]\n",left,right);
		return_query = dynamic_query(a,root -> right,left,right);	
	}
	else if (left <= pivot && right > pivot )
	{
		//printf("[%d:%d]\n[%d:%d]\n",left,pivot,pivot+1,right);
		return_query = compare_queries(dynamic_query(a,root -> left , left , pivot),dynamic_query(a,root -> right, pivot + 1, right ));
		
	}
	//return_query_pair = max_element(return_query.begin(), return_query.end(),min_freq);
	return return_query;
}
int main()
{
	int n;
	int i;
	map<int,int> rquery;
	map<int,int>::iterator it;
	scanf("%d",&n);
	int a[n];
	int left,right;
	string output;

	struct node *root;
	
	
	for ( i = 0; i < n; i ++ )
	{
		scanf("%d",&a[i]);
	}

	
	root = (struct node * ) malloc(sizeof(struct node));
	root -> i = 0;
	root -> j = n-1;
	root -> right = NULL;
	root -> left = NULL;
	rquery = createSegmentTree(root,a);
	

	int test_cases;
	scanf("%d",&test_cases);
	for ( i = 0; i < test_cases; i ++ )
	{
		scanf("%d%d",&left,&right);
		rquery = dynamic_query(a,root,left,right);
		it = max_element(rquery.begin(),rquery.end(),min_freq);
		printf("%d:%d\n",it -> first,it -> second);
		//output.append("%d\n",rquery);
	}
	//cout << output;
	

	
}
