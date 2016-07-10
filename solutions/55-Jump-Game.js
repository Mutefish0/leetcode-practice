/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    if(nums.length==1) return true
    let ret=true,gate
    for(let i=nums.length-2;i>=0;i--){
        if(!ret&&nums[i]>gate-i) ret=true
        else if(ret&&nums[i]===0){
            ret=false
            gate=i
        }
    }
    return ret
}