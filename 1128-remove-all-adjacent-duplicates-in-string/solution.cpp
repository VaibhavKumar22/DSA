class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>n;
        int i=s.size()-1;
        while(i>=0){
            if(!n.empty())
            if(n.top()==s[i]){
                n.pop();
                i--;
                continue;
            }

            n.push(s[i]);
            i--;

        }
        s="";
        while(!n.empty()){
            s+=n.top();
            n.pop();
        }
        return s;

        
    }
};
