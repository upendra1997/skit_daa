#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int> &array){
    int low=0, high=array.size(), mid = 0;
    if(array[low]==1)
        return 0;
    else if(array[high-1]==0)
        return -1;
    while(low<high){
        mid = low + (high - low) / 2;
        if(array[mid]==1 and array[mid-1]==0)
            return mid;
        else if(array[mid]==0)
            low = mid;
        else if(array[mid]==1)
            high=mid;
    }
    return mid;
}

int main(int argc, char const *argv[])
{
	
	int n,result;
	vector<int> v;
	while(cin>>n){
		v.push_back(n);
	}
	result = bin_search(v);
	if(result==-1)
		cout<<"No one found.\n";
	else
		cout<<"one at index "<<result<<"\n";
}