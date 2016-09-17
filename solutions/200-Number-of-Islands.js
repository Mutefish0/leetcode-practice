/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if(!grid) return 0 
    var m = grid.length  
    if(m===0) return 0
    var n = grid[0].length 
    
    var labelGrid = []
    var queue = []
    var label = 0
    for(var i=0;i<m;i++) labelGrid[i] = []

    function _bfs(toY, toX){
        label++      
        queue = [[toY,toX]]
        while(queue.length>0) {
            var head = queue.shift()
            var y = head[0]
            var x = head[1]
            
            if(grid[y][x]==='1'&&!labelGrid[y][x]/*由于push时没有设置灰色标志*/) {
                labelGrid[y][x] = label
                //up 
                if(y-1>=0) queue.push([y-1,x])
                //right 
                if(x+1<n) queue.push([y,x+1])
                //down 
                if(y+1<m) queue.push([y+1,x])
                //left
                if(x-1>=0) queue.push([y,x-1])
            }  
        }
    }

    for(var y=0;y<m;y++) {
        for(var x=0;x<n;x++) {
            if(grid[y][x]==='0'||labelGrid[y][x]) continue
            _bfs(y,x)
        }
    }

    return label 
};


/**
 * coordinate 
 *
------- x
|
|
|
|

y
*/
/*
var data=[
"11111110111111111111",
"11111101110101011111",
"11111111111000111100",
"10101111010101101111",
"10111111011001110111",
"01111101101001110111",
"11111111011101011111",
"11111011111010101011",
"01111111010110111001",
"01000111111011101010",
"01111111110000111111",
"10110111111111110101",
"11111101011010111111",
"11111111111011111110",
"11010111011111111111",
"11111101110111011001",
"10111111111100111111",
"10011100110111001111",
"11101100010011110011",
"11111111011111110101"]

console.log(numIslands(data))
*/