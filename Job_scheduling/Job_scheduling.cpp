#include <bits/stdc++.h>
using namespace std;
#define exch(array,i,j){ pii temp=array[i];array[i]=array[j];array[j]=temp;}
typedef pair<int,int> pii;

int decrease(vector<pii> &array){
	int flag=0;
	for(int i=0;i<array.size();i++)
		if(array[i].second!=0){
			array[i].second--;
			flag++;
		}
		return flag;
}

// void print(std::vector<pii> &v){
// 	for(int i=0;i<v.size();i++)
// 		printf("%d %d, ",v[i].first, v[i].second );
// 	printf("\n");
// }

int main(int argc, char const *argv[])
{
	int d,n,profit=0;
	vector<pii> array;
	scanf("%d",&n);
	while(n--){
		pii temp;
		scanf("%d%d",&temp.first,&temp.second);
		array.push_back(temp);
	}
	scanf("%d",&d);
	sort(array.rbegin(),array.rend());
	vector<pii>::iterator i=array.begin();
	while(d and i!=array.end()){
		// print(array);	
		if((*i).second==0){
			i++;
			continue;
		}
		profit+=(*i).first;
		(*i).second=0;
		i++;
		d--;
		if(!decrease(array)) break;
	}
	printf("Optimal Profit is %d.",profit);
	return 0;
}