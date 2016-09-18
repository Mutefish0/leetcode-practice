/**
 * @param {number} n
 * @return {number}
 */
var lastRemaining = function(n) {
    // operate stack --- 0 -> x*2; 1 -> x*2-1 
    var stack = []
    // true -> left to right; false -> right to left 
    var dir = true 

    while(n>1) {
        if(n%2!=0||dir) stack.push(0)
        else stack.push(1)
        dir = !dir
        n = Math.floor(n/2)
    }

    var result = 1
    while(stack.length>0) {
        if(stack.pop()) result = result*2 - 1
        else result = result*2
    }

    return result
};