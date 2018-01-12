#include<bits/stdc++.h>
#define exch(array,i,j){int temp=array[i];array[i]=array[j];array[j]=temp;}
using namespace std;

void merge(vector<int> &array, int l, int m, int h){
	int low,low1,high,high1;
	for(int i=low;i<high;i++)
}

void mergesort(vector<int> &array, int low, int high){
	if(high-low==1) return;
	if(high-low == 2){
		if(array[low]<array[high-1]) return;
		exch(array,low,high-1);
		return;
	}
	int mid = low+(high-low)/2;
	printf("merge low=%d mid=%d high=%d\n",low,mid,high);
	mergesort(array, low, mid);
	mergesort(array, mid, high);
	merge(array, low, mid, high);
}

int main()
{
	vector<int> vec;
	int temp;
	while(cin>>temp){
		vec.push_back(temp);
	}
	int len =  vec.size();
	mergesort(vec,0,len);
	for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
	return 0;
}
