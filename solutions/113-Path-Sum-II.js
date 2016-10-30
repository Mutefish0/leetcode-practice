/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    if(!root) return []
    var ret = []
    var queue = [root]
    root.sum = 0
    root.path = []
    while(queue.length) {
        var head = queue.shift()
        head.sum += head.val
        head.path.push(head.val)

        if(!head.left && !head.right) {
            if(head.sum == sum)
                ret.push(head.path)
            continue;
        }
        if(head.left) {
            head.left.sum = head.sum
            head.left.path = head.path.concat([])
            queue.push(head.left)
        }
        if(head.right) {
            head.right.sum = head.sum
            head.right.path = head.path.concat([])
            queue.push(head.right)
        }
    }

    return ret 
};