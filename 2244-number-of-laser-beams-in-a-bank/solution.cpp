class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0;
        int prev = 0;

        for (const string& row : bank) {
            int curr = 0;
            for (char c : row) {
                if (c == '1') curr++;
            }

            if (curr > 0) {
                beams += prev * curr;
                prev = curr;
            }
        }

        return beams;
    }
};

