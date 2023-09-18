#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    int n;
    cin >> n;
    while (n--){
        string func;
        cin >> func;
        if (func == "push"){
            int val;
            cin >> val;
            s.push(val);
        }
        else if (func == "pop"){
            if (s.empty()){
                cout << "NONE" << endl;
            }
            else {
                s.pop();
            }
        }
    }
    stack<int> tmp;
    while (!s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
}