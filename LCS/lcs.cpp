#include <bits/stdc++.h>
using namespace std;

// s = ABCBDAB
// s = BDCABA


//int m,n;


void lcs(string &x, string &y, vector<vector< int> > &c, vector<vector< char> > &d){
    int m = x.size(), n = y.size();
    for(int i = 1; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0;j <= n; j++)
        c[0][j] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
//            printf("%c-%c\n",x[i-1],y[j-1]);
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                d[i][j] = '\\';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                d[i][j] = '|';
            }
            else if(c[i-1][j] < c[i][j-1]){
                c[i][j] = c[i][j-1];
                d[i][j] = '-';
            }
        }
    }
}

void print_mat(vector<vector<char> > &d){
    for(auto i: d){
        for(auto j: i){
            cout<<j;
        }
        cout<<endl;
    }
}

void print_mat(vector<vector<int > > &c){
    for(auto i: c){
        for(auto j: i){
            cout<<j;
        }
        cout<<endl;
    }
}

void print_lcs(vector<vector<char> > &d, string &a, int i, int j){
//    printf("%d %d",i,j);
    if(i==0 or j==0)
        return;
    if(d[i][j] == '\\'){
        print_lcs(d, a, i - 1, j - 1);
        printf("%c",a[i-1]);
    }
    else if(d[i][j] == '|')
        print_lcs(d, a, i - 1, j);
    else
        print_lcs(d, a, i, j - 1);
}

int main() {
//    string a="ABCBDAB",b="BDCABA";
    string a,b;
    cout<<"Please Enter a String"<<endl;
    cin>>a;
    cout<<"Please Enter a substring"<<endl;
    cin>>b;
//    cout<<a<<" "<<b<<endl;
    int m = a.size(),n = b.size();
    vector< vector<int> > c;
    vector< vector<char> >d;
    for(int i=0;i<=m;i++){
        vector<int> temp(n+1);
        vector<char> temp1(n+1);
        c.push_back(temp);
        d.push_back(temp1);
    }
//    int c[m+1][n+1];
//    char d[m+1][n+1];
    lcs(a, b, c, d);
//    print_mat(c);
//    print_mat(d);
    print_lcs(d, a, m, n);
    return 0;
}