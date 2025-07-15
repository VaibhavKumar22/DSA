class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)return false;
        bool vowel=false;
        bool consonant=false;
        // bool digit=false;
        for(int i=0;i<word.length();i++){
            if(!isalnum(word[i]))return false;
            // if(isdigit(word[i]))digit=true;
            char c=tolower(word[i]);
            if(isalpha(c)){
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                    vowel=true;
                }else{
                    consonant=true;
                }
            }

        }
        return vowel && consonant;
    }
};
