#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

map<string, int> mapping;
map<string, int> reportCount;
vector<string> reportList[1010];
vector<string> blacklist;

void countReport(vector<string> report, int k) {
    int num = 1;
    for (int i = 0; i < report.size(); i++) {
        string str = report[i];
        stringstream streamStr(str);
        string userID, blacklistID;
        streamStr >> userID >> blacklistID;

        if (mapping[userID] == 0) mapping[userID] = num++;
        if (mapping[blacklistID] == 0) mapping[blacklistID] = num++;
        if (find(reportList[mapping[userID]].begin(), reportList[mapping[userID]].end(), blacklistID) == reportList[mapping[userID]].end()) {
            reportList[mapping[userID]].push_back(blacklistID);
            reportCount[blacklistID]++;
            if (reportCount[blacklistID] >= k) {
                blacklist.push_back(blacklistID);
            }
        }
    }
}

vector<int> findAnswer(vector<string> id_list) {
    vector<int> answer;
    for (auto userID : id_list) {
        int mappingID = mapping[userID];
        int result = 0;
        for (auto reportID : reportList[mappingID]) {
            if (find(blacklist.begin(), blacklist.end(), reportID) != blacklist.end()) {
                result++;
            }
        }
        answer.push_back(result);
    }
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    countReport(report, k);
    answer = findAnswer(id_list);
    return answer;
}
