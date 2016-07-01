/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let ret = []
    let top = -1
    let end = {val:0,next:null}
    end.next = end
    while(l1!=end||l2!=end){
        if(ret[top]>9) {
            ret[top] -= 10
            ret.push(l1.val+l2.val+1)
        }
        else ret.push(l1.val+l2.val)
        l1 = l1.next?l1.next:end
        l2 = l2.next?l2.next:end
        top ++
    }
    if(ret[top]>9){
        ret[top] -= 10
        ret.push(1)
    }
    return ret
}