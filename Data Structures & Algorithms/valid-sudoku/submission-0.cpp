class Solution {
public:
    bool areAllEleUnq(int rfrom, int cfrom, int rto, int cto, vector<vector<char>>& board){

        map<char, int> hasmap;

        for(int i = rfrom; i <= rto; i++){
            for(int j = cfrom; j <= cto; j++){
                if((board[i][j] != '.') && (hasmap[board[i][j]])){
                    return false;
                }
                else{
                    hasmap[board[i][j]]++;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 cases horizontal, vertical and 3x3  should be checked

        // horizontal
        for(int i = 0; i < 9; i++){
            if(!areAllEleUnq(i, 0, i, 8, board)){
                return false;
            }
        }

        // vertical
        for(int i = 0; i < 9; i++){
            if(!areAllEleUnq(0, i, 8, i, board)){
                return false;
            }
        }

        // 3x3 matrix
        for(int i = 0; i < 3; i++){
            if(!areAllEleUnq((i * 3), 0, (i * 3) + 2, 2,board)){
                return false;
            }
            if(!areAllEleUnq((i * 3), 3, (i * 3) + 2, 5, board)){
                return false;
            }
            if(!areAllEleUnq((i * 3), 6, (i * 3) + 2, 8, board)){
                return false;
            }
        }

        return true;

    }
};
