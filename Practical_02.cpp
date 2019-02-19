#include<iostream>
#include<string>
#include<vector>

using namespace std;

void addEdge(vector <pair<int, int> > adj[], int u,
             int v, int wt){
    adj[u].push_back(make_pair(v, wt));
}

void init_graph(vector<pair<int,int>>adj[]){
    addEdge(adj, 0, 0, 0);
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 0, 1);
    addEdge(adj, 1, 2, 0);
    addEdge(adj, 2, 1, 0);
    addEdge(adj, 2, 2, 1);
}

class DFA{
    int state;
    string input_str;
    vector<pair<int,int>> graph[3];
public:
    DFA(){}
    DFA(string init_string){
        input_str = init_string;
        state = 0;
        init_graph(graph);
        
    }
     void evaluate_str(){
         for(auto x: input_str){
             //cout<<x<<endl;
             //int inp_char = int(x);
             x = int(x)-48;
             vector<pair<int,int>> vec = graph[state];
             for(int i = 0;i<vec.size();i++){
                 int new_state = get<0>(vec[i]);
                 
                 int weight = get<1>(vec[i]);
                 //cout<<weight<<" "<<x<<endl;
                 if(weight== x){
                     cout<<"State Transition: "<<state<<"--->"<<new_state<<endl;
                     state = new_state;
                     break;
                 }
                 
             }
         }
         if(state == 0){
             cout<<"Binary string divisible by 3"<<endl;
         }
         else{
             cout<<"Binary string not divisible by 3 and remainder is: "<<state<<endl;
         }
         
     }
};

int main(){
    DFA dfa_obj = DFA("1001");
    dfa_obj.evaluate_str();
    
    return 0;
}
