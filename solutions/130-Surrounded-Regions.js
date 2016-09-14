/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    var n = board.length
    //小于3的不需要操作
    if(n<3) return
    var m = board[0].length 
    //小于3的不需要操作
    if(m<3) return
    //记录所有可以逃脱的点 `Point`
    var escapes = []
    //用于广度优先遍历的队列
    var queue = []
    //记录左右两边为O的点
    for(var i=0;i<n;i++) {
        //左边
        if(board[i][0]==='O') queue.push(new Point(i,0)) 
        //右边
        if(board[i][m-1]==='O') queue.push(new Point(i,m-1))
        
        escapes.push([])
    }
    //记录上下两边为O的点
    for(var i=0;i<m;i++) {
        //上边
        if(board[0][i]==='O') queue.push(new Point(0,i))
        //下边
        if(board[n-1][i]==='O') queue.push(new Point(n-1,i))
    }
    //广度优先遍历
    while(queue.length>0) {
        var p = queue.shift()
        //记录该逃脱的点
        if(board[p.x][p.y]==='O') escapes[p.x][p.y] = 1
        else continue 
        //
        var next = p.nextPoints(n, m, escapes)

        if(next.up) queue.push(next.up)
        if(next.right) queue.push(next.right)
        if(next.bottom) queue.push(next.bottom)
        if(next.left) queue.push(next.left)
    }

    for(var i=0;i<n;i++) {
        for(var j=0;j<m;j++)
            if(!escapes[i][j]) board[i][j] = 'X'
    }
};


class Point{
    constructor(x, y) {
        this.x = x
        this.y = y
    }
    //探索旁边的点
    nextPoints(n, m, escapes/*记录*/) {
        var next = {}
        //up
        if(this.x-1>=0 &&!escapes[this.x-1][this.y]) 
            next.up = new Point(this.x-1,this.y)
        //right
        if(this.y+1<=m-1&&!escapes[this.x][this.y+1]) 
            next.right = new Point(this.x,this.y+1)
        //bottom 
        if(this.x+1<=n-1&&!escapes[this.x+1][this.y]) 
            next.bottom = new Point(this.x+1,this.y)
        //left 
        if(this.y-1>=0&&!escapes[this.x][this.y-1]) 
            next.left = new Point(this.x,this.y-1)
        
        return next
    }

}   

/**
 * coordinate 
 *
 
 ----------- y
| X X X X 
| X O X X
| X O X X 
| O X X X
|
x

 */
  
/**
 * test
 *
var bd = [
['X','O','X','O','X','O'],
['O','X','O','X','O','X'],
['X','O','X','O','X','O'],
['O','X','O','X','O','X'],
]
solve(bd) 
console.log(bd)
*/


