1617. Count Subtrees With Max Distance Between Cities


class Solution {
public:
    int max_depth = 0, farthest_node = 0;

    bool isConnected(int &nodes, unordered_map<int, vector<int>> &adj, int curr, int depth  ){
        nodes = nodes^(1<<curr);
        if( depth>max_depth )
            max_depth = depth, farthest_node = curr;  
        max_depth = max( max_depth, depth );
        if( !nodes ) return true;
        int ans = false;
        for( auto num: adj[curr] )
            if( nodes & 1<<num )
                ans |= isConnected( nodes, adj, num, depth+1 );
        return ans;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        map<int,int> mp; unordered_map<int, vector<int>> adj;
        for( int i=0; i<edges.size(); i++ ){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for( int num=1; num<pow(2,n+1); num++ ){
            if(!(num%2)){
                int curr = 1, temp = num/2;
                while( !(temp%2) )
                    curr++, temp /= 2;
                temp = num, max_depth = 0, farthest_node = curr;
                if(isConnected(temp, adj, curr, 0)){
                    temp = num;
                    isConnected(temp, adj, farthest_node, 0);
                    mp[max_depth]++;
                }
            } 
        }
        vector<int> ans(n-1,0);
        for( int i=1; i<n; i++ )
            if(mp[i]) ans[i-1]=mp[i];

        return ans;
    }
};



