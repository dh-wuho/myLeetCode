class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> firstCells, nextCells(cells.size(), 0);
        int cycle = 0;
        
       while(N > 0) {
           N--;
           for(int j = 1; j < cells.size() - 1; j++) {
               nextCells[j] = (cells[j - 1] == cells[j + 1]);
           }
           if(cycle == 0) {
               // start from 1 to remove edge case, which cells[0] = 1 or cells[7] = 1.
               firstCells = nextCells;
           }
           else if(nextCells == firstCells) {
               N %= cycle; 
           }
           cycle++;  
           cells = nextCells;
       }
        return nextCells;
    }   
    
};