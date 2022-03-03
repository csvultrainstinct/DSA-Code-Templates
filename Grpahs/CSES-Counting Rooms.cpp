/*
You are given a map of a building, and your task is to count the number of its rooms. 
The size of the map is n×m squares, and each square is either floor or wall. 
You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n and m: the height and width of the map.

Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

#include <bits/stdc++.h>

using namespace std;

int n,m;
bool vis[1001][1001];
char grid[1001][1001]; 

bool isValid(int x,int y){
    if(x<0||x>n-1||y<0|y>m-1) return false;
    
    if(vis[x][y]==true || grid[x][y]=='#') return false;
    
    return true;
}

void dfs(int x,int y){
    vis[x][y]=true;
    
    if(isValid(x-1,y))
      dfs(x-1,y);
     
    if(isValid(x,y+1))
      dfs(x,y+1);
    
    if(isValid(x+1,y))
      dfs(x+1,y);
     
    if(isValid(x,y-1))
      dfs(x,y-1);
}

int main()
{
    cin>>n>>m;
    for(auto i=0;i<=n-1;i++){
        for(auto j=0;j<=m-1;j++){
            cin>>grid[i][j];
        }
    }
    int noOfRooms=0;
    for(auto i=0;i<=n-1;i++){
        for(auto j=0;j<=m-1;j++){
            if(grid[i][j]=='.' && vis[i][j]==false){
                dfs(i,j);
                noOfRooms++;
            }
            
        }
        
    }
    
    cout<<noOfRooms<<endl;

    return 0;
}
