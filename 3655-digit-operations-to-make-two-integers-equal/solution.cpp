class Solution {
public:
    
    static bool done;
    static const int MAXN = 20000;
    static vector<bool> is_Prime;
    const int INF = 2e9;
    
    void sieve() {
        is_Prime[0] = is_Prime[1] = false;
        for(int i = 2; i * i < MAXN; i++) {
            if(is_Prime[i]) {
                for(int j = i * i; j < MAXN; j += i) {
                    is_Prime[j] = false;
                }
            }
        }
        done = true;
    }
    
    vector<int> get_neighbour(int num) {
        vector<int> result;
        string s = to_string(num);
        
        for(int i = 0; i < s.size(); i++) {
            char original = s[i];
            
            if(s[i] < '9') {
                s[i]++;
                int next = stoi(s);
                if(!is_Prime[next])
                    result.push_back(next);
                s[i] = original;
            }
            
            if(s[i] > '0') {
                s[i]--;
                int next = stoi(s);
                if(!is_Prime[next])
                    result.push_back(next);
                s[i] = original;
            }
        }
        
        return result;
    }
    
    int minOperations(int n, int m) {
        
        if(!done) sieve();
        
        if(is_Prime[n] || is_Prime[m])
            return -1;
        
        vector<int> dis(MAXN, INF);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        dis[n] = n;
        pq.push({n, n});
        
        while(!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();
            
            if(cur == m)
                return cost;
            
            if(cost > dis[cur])
                continue;
            
            vector<int> neighbours = get_neighbour(cur);
            
            for(int next : neighbours) {
                int newCost = cost + next;
                
                if(newCost < dis[next]) {
                    dis[next] = newCost;
                    pq.push({newCost, next});
                }
            }
        }
        
        return -1;
    }
};

bool Solution::done = false;
vector<bool> Solution::is_Prime(Solution::MAXN, true);

