/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if(!root) return true
    return helper([root.left,root.right])
};

/**
 * 判断该层是否是对称的
 * @param {Array} 该层的节点数组  
 * @return {Array} 下层的节点数组 {null} 不满足对称
 */

function helper(nodes) {
    if(nodes.length===0) return true
    var nextLayer = []
    for(var i=0,t=nodes.length/2;i<t;i++) {
        //两个节点都为null
        if(!nodes[t-i-1]&&!nodes[t+i]) continue
        //有一个节点是null而另一个不是
        else if(!nodes[t-i-1]||!nodes[t+i]) return false
        else if(nodes[t-i-1].val===nodes[t+i].val) {
           nextLayer.unshift(nodes[t-i-1].right)
           nextLayer.unshift(nodes[t-i-1].left)

           nextLayer.push(nodes[t+i].left)
           nextLayer.push(nodes[t+i].right)
        }
        else return false
    }
    return helper(nextLayer)
}



