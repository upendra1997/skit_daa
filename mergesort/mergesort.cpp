#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& array1,vector<int>& array2){
	vector<int> result;
	int i=0,j=0;
	while(i<array1.size() and j<array2.size()){
		if(array1[i]<array2[j])
			result.push_back(array1[i++]);
		else
			result.push_back(array2[j++]);
	}
	if(i<array1.size())
		while(i<array1.size())
			result.push_back(array1[i++]);
	if(j<array2.size())
		while(j<array2.size())
			result.push_back(array2[j++]);
	return result;
}

vector<int> mergesort(vector<int> &array){
	if(array.size()==1) return array;
	int mid = array.size()/2;
	vector<int>array1(array.begin(),array.begin()+mid);
	vector<int>array2(array.begin()+mid,array.end());
	vector<int> arr1=mergesort(array1), arr2=mergesort(array2);
	return merge(arr1,arr2);
}

int main()
{
	vector<int> vec;
	int temp;
	cin>>temp;
	while(temp--){
		int t=0;
		cin>>t;
		vec.push_back(t);
	}
	vector<int> result = mergesort(vec);
	for(int i=0;i<result.size();i++) cout<<result[i]<<" "; cout<<"\n";
	return 0;
}
