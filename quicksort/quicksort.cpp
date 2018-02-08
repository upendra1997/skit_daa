#include<bits/stdc++.h>

using namespace std;

void part(vector<int> &array, int low, int high, int mid){
	while(low<high){
		while(array[low]<array[mid]) low++;
		while(array[high]>array[mid]) high--;
		int temp=array[low];
		array[low] = array[high];
		array[high] = temp;
	}
}

void quick(vector<int> &array, int low, int high){
	if(high - low == 1){
		if(array[low]<array[high]) return;
		int temp=array[low];
		array[low] = array[high];
		array[high] = temp;
		return;
	}
	if(high == low) return;
	int mid = low+(high-low)/2;
	part(array, low, high, mid);
	quick(array, low, mid);
	quick(array, mid, high);
}

int main()
{
	vector<int> vec;
	int temp;
	int n=0;
	cin>>n;
	while(n--){
		cin>>temp;
		vec.push_back(temp);
	}
	int len =  vec.size();
	quick(vec,0,len-1);
	for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
	return 0;
}
