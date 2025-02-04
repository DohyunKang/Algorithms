#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> card;
    
    int data;
    
    for(int i = 0; i < N; i++)
    {
        cin >> data;
        card.push(data);
    }
    
    int data1;
    int data2;
    int sum = 0;
    
    while(card.size() != 1)
    {
        data1 = card.top();
        card.pop();
        data2 = card.top();
        card.pop();
        
        sum += data1+ data2;
        
        card.push(data1+data2);
    }
    
    
    cout << sum << "\n";
    
    return 0;
}