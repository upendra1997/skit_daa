#include <bits/stdc++.h>
using namespace std;

typedef struct _{int value;int weight;} data;

bool sortfunc(const data &left,const data &right){
	double ratiol = 1.0*left.value/left.weight;
	double ratior = 1.0*right.value/right.weight;
	if(abs(ratiol-ratior)<=1e-9)
		return left.value > right.value;
	else
		return (double)ratiol > (double)ratior; 
}

float cost(vector<data> array,int Weight){
	float cost=0.0;
	int i=0;
	stable_sort(array.begin(),array.end(),sortfunc);
	// for(int k=0;k<array.size();k++) printf("%d %d,", array[k].value,array[k].weight);
	printf("\n");
	while(Weight>array[i].weight and i<array.size()){
		cost += array[i].value;
		Weight -= array[i++].weight;
	}
	if(i<array.size()){
		cost+=array[i].value*Weight*1.0/array[i].weight;
	}
	return cost;
}

int main(){
	int n,W;
	printf("Number of items: ");
	scanf("%d",&n);
	vector<data> array;
	while(n--){
		printf("Items Value and Weight: ");
		data temp;
		scanf("%d %d",&temp.value,&temp.weight);
		array.push_back(temp);
	}
	printf("Weight of Knapsack: ");
	scanf("%d",&W);
	printf("Optimal cost %f\n",cost(array,W));
	return 0;
} 