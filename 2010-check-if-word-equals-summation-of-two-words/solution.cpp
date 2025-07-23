class Solution {
public:
    int a(string b){
        int sum=0;
        for(char c:b){
            sum=sum*10+(c-'a');
        }
        return sum;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return a(firstWord)+a(secondWord)==a(targetWord);



    }
};
