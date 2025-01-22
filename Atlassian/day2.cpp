1600. Throne Inheritance

class ThroneInheritance {
public:
    unordered_map<string,vector<string>> bche;
    unordered_map<string,bool> dead;
    string king;
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    void birth(string parentName, string childName) {
        bche[parentName].push_back(childName);
    }
    void death(string name) {
        dead[name]=1;
    }
    void dfs(vector<string>& ans,string papa){
        if(!dead[papa]) ans.push_back(papa);
        for(auto bcha:bche[papa]){
            dfs(ans,bcha);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans,king);
        return ans;
    }
};
/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */


