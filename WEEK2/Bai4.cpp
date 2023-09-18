#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    int n;
    cin >> n;
    while (n--){
        string func;
        cin >> func;
        if (func == "enqueue"){
            int val;
            cin >> val;
            q.push(val);
        }
        else if (func == "dequeue"){
            if (q.empty()){
                cout << "NONE" << endl;
            }
            else {
                q.pop();
            }
        }
    }
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}