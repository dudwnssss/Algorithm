#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    // 숫자의 개수 세기
    int count[100001]={0};

    string temp="";
    // 문자열을 돌며 나오는 수들의 개수를 세기
    for(auto ch : s){
        if(ch-'0'>=0 && ch-'0'<=9){ //숫자면
            temp=temp+ch; //temp에다 씀
        }else{
            if(temp.length()){
                count[stoi(temp)]++;
                temp="";
            }
        }
    }

    vector<pair<int,int>> v;
    for(int i=1;i<=100000;i++){
        if(count[i]){
            v.push_back({count[i],i});
        }
    }
    // 가장 많이 나온 순으로 오름차순 후 뒤집기
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for(auto el:v){
        cout<<el.second<<'\n';
        answer.push_back(el.second);
    }
    return answer;
}