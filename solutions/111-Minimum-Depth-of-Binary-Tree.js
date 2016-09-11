/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if(!root) return 0 
    var min = 1 
    walker(root, function(node, end) {
        if(!node.left&&!node.right) {
            min = node.depth
            end()
        }
    })
    return min 
};

/**
 * 广度遍历函数
 * @param  {[TreeNode]}   [从给定的节点开始遍历，若给定节点没有depth成员，则depth默认为1]
 * @param  {Function} fn   [遍历处理函数，接受一个TreeNode参数,还接受一个end方法，掉用后结束遍历]
 */
function walker(node, fn) {
    if(!node) return 
    node.depth = node.depth || 1
    var queue = [node] 
    var brk = false 
    function end() {
        brk = true
    }
    while(queue.length>0) {
        var head = queue.shift()
        fn(head, end)  
        if(brk) return 
        if(head.left) {
            head.left.depth = head.depth + 1 
            queue.push(head.left)
        }
        if(head.right) {
            head.right.depth = head.depth + 1
            queue.push(head.right)
        }
    }
}