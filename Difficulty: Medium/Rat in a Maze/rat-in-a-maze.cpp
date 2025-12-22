class Solution {
  private:
    bool pos(vector<vector<int>>& maze, vector<vector<int>>& visited, int n, int x, int y){
        if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && visited[x][y]==0) return true;
        else return false;
    }
    
    void solve(vector<vector<int>>& maze, vector<string>& res, vector<vector<int>>& visited, int n, int x,
    int y, string s){
        if(x==n-1 && y==n-1){
            res.push_back(s);
            return;
        }
        visited[x][y]=1;
        
        //down
        if(pos(maze,visited,n,x+1,y)){
            solve(maze,res,visited,n,x+1,y,s+"D");
        }
        
        //left
        if(pos(maze,visited,n,x,y-1)){
            solve(maze,res,visited,n,x,y-1,s+"L");
        }
        
        //right
        if(pos(maze,visited,n,x,y+1)){
            solve(maze,res,visited,n,x,y+1,s+"R");
        }
        
        //up
        if(pos(maze,visited,n,x-1,y)){
            solve(maze,res,visited,n,x-1,y,s+"U");
        }
        visited[x][y]=0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>res;
        int n=maze.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        if(maze[0][0]==1)solve(maze,res,visited,n,0,0,"");
        return res;
    }
};