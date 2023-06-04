class Solution {
public
    void dfs(vectorvectorint& k, int i, vectorbool& visited) {
        visited[i] = true;
        int n = k.size();
        for (int j=0; jn; j++) {
            if (k[i][j]==1 && visited[j]==false) {
                dfs(k, j, visited);
            }
        }
    }
    
    int findCircleNum(vectorvectorint& k) {
        int n = k.size();
        vectorbool visited(n, false);
        int c = 0;
        for (int i=0; in; i++) {
            if (visited[i]==false) {
                c++;
                dfs(k, i, visited);
            }            
        }
        return c;
    }
};


// Solution 2

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> visited;
        int ret = 0;
        for(int i = 0 ; i < isConnected.size(); ++i){
            if(visited.find(i) == visited.end()){
                dfs(isConnected, visited, i);
                ret++;
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& isConnected, set<int> &visited, int i) {
        if(visited.find(i) != visited.end()) {
            return;
        }
        visited.insert(i);
        for(int j = 0; j < isConnected[i].size(); ++j){
            if(isConnected[i][j] == 1) {
                dfs(isConnected, visited, j);
            }
        }
    }
};