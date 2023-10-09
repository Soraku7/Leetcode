#include<iostream>
#include<vector>
#include<string>
using namespace  std;

int main(){
    vector<vector<int>> a(5 , vector<int>(2));
    vector<vector<string>> strs;
    strs.push_back(vector<string>(3 , "a"));
    cout << strs[0][0];
}
