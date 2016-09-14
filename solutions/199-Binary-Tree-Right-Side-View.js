/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    if(!root) return []
    var rel = []
    var lastDepth = 1
    var lastNode = root

    walker(root, node => {
        if(node.depth>lastDepth) {
            rel.push(lastNode.val)
            lastDepth = node.depth
            lastNode = node 
        }
    })

    rel.push(lastNode.val)

    return rel 
}
/**
 * 广度遍历函数
 * @param  {[TreeNode]}   [从给定的节点开始遍历，若给定节点没有depth成员，则depth默认为1]
 * @param  {Function} fn   [遍历处理函数，接受一个TreeNode参数]
 */
function walker(node, fn) {
    if(!node) return 
    node.depth = node.depth || 1
    var queue = [node] 
    while(queue.length>0) {
        var head = queue.shift()
        fn(head)
        if(head.right) {
            head.right.depth = head.depth + 1
            queue.push(head.right)
        }
        if(head.left) {
            head.left.depth = head.depth + 1 
            queue.push(head.left)
        }
    }
}