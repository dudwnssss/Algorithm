#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp (pair<string,int>a,pair<string,int>b){
    return a.second>b.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<course.size(); i++){
        map <string, int> m;
        for(int j=0; j<orders.size(); j++){
            string s= orders[j];
            if(course[i]>s.size())continue;
            sort(s.begin(),s.end());
            vector <bool> check (s.size(),0);
            for(int k=s.size()-course[i]; k<s.size(); k++) check[k]=1;
            do{
                string s1 ="";
                for(int k=0; k<s.size(); k++){
                    if(check[k])s1+=s[k];
                }
                m[s1]++;
            }while(next_permutation(check.begin(),check.end()));
        }
        if(m.empty())continue;
        vector <pair<string, int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(), cmp);
        if(v.begin()->second==1)continue;
        for (auto x : v)cout<< x.first <<" "<<x.second<<endl;
        int compare = v.begin()->second;
        for(auto x : v){
            if(x.second==compare)answer.push_back(x.first);
            else break;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}