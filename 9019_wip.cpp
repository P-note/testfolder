#include <iostream>
#include <string>
#include <queue>
using namespace std;

string arr[10000];

int bfs(int begin, int target){
    queue<int> q;
    bool visited[10000];
    arr[begin].clear();
    std::cout<<arr[begin]<<"is arr[begin]"<<endl;
    q.push(begin);
    visited[begin] = true;
    while(!q.empty()){
        int curr = q.front();
        if(curr == target){
            return 1;
        }
        q.pop();
        
        int dnum = (curr*2)%10000;
        if(!visited[dnum]){
            visited[dnum] = true;
            q.push(dnum);
            arr[dnum] = arr[curr] + 'D';
        }
        int snum = curr-1;
        if(curr == 0) snum = 9999;
        if(snum > 0 && !visited[snum]){
            visited[snum] = true;
            q.push(snum);
            arr[snum] = arr[curr] + 'S';
        }
        string str = to_string(curr);
        string strl = str + str;
        strl = strl.substr(1, str.length());
        string strr = str + str;
        strr = strr.substr(str.length()-1, str.length());
        int lnum = stoi(strl);
        int rnum = stoi(strr);
        cout<<lnum<<' '<<rnum<<"is lnum, rnum"<<endl;
        if(!visited[lnum]){
            visited[lnum] = true;
            q.push(lnum);
            arr[lnum] = arr[curr] + 'L';
        }
        if(!visited[rnum]){
            visited[rnum] = true;
            q.push(rnum);
            arr[rnum] = arr[curr] + 'R';
        }
    }

    return 0;
}

int main(void){
    int t,a,b;
    cin>>t;
    for (int i = 0; i < t; i++){
        cin>>a>>b;
        bfs(a,b);
        cout<<arr[b]<<endl;
    }

    return 0;
}
