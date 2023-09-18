#include <bits/stdc++.h>
using namespace std;
class MyStack{
    queue<int>q;
    public:
    void push(int x){
        queue<int>tmp;
        while (!q.empty()){
            tmp.push(q.front());
            q.pop();
        }
        // add x to front to pop
        q.push(x);
        // add again
        while (!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
    }
    void pop(){
        if (!q.empty()){
            q.pop();
        }
    }
    int top(){
        if (!q.empty()){
            return q.front();
        }
        return -1;
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    return 0;
}