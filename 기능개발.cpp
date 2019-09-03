/* 내 풀이

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    bool chk[100]={};
    while(1){
        int day = 0;
        int add = 0;
        int cur;
        for(int i=0;i<progresses.size();i++){
            if(chk[i]) continue;
            if(day == 0){
                day = (100-progresses[i])/speeds[i] + ((100-progresses[i])%speeds[i] > 0);
                cur = i;
            }
            progresses[i] += day*speeds[i];
            printf("%d\n",day*speeds[i]);
            if(progresses[i] >= 100 && cur == i) add++,cur++,chk[i] = true;
        }
        if(!add) return answer;
        answer.push_back(add);
    }
    return answer;
}

*/

// queue를 이용한 풀이
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        q.push((100-progresses[i])/speeds[i] + ((100-progresses[i])%speeds[i] > 0) );
    }
    while(!q.empty()){
        int pivot = q.front();
        int add = 1;
        q.pop();
        while(!q.empty() && pivot >= q.front()){
            add++;
            q.pop();
        }
        answer.push_back(add);
    }
    return answer;
}