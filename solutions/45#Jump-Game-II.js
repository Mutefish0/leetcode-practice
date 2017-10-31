/**
 * @param {number[]} nums
 * @return {number}
 */
//线性时间解法
//maxReach表示在仅使用位置i及i之前的元素时，走step步能够到达的最远位置
//maxReachOneMoreStep表示在仅使用位置i及i之前的元素时，
//走step+1步能到达的最远位置
let jump = function (nums) {
    let step = 0, maxReach = 0, maxReachOneMoreStep = 0
    //i表示从位置0走到位置i时的情况
    for (let i = 0; i < nums.length; i++) {
        //位置i正好超过了当前步数能够到达的最远位置maxReach,需要再走一步，
        //并且更新多走一步之后的能够到达的最远位置maxReach
        if (i > maxReach) {
            step++
            maxReach = maxReachOneMoreStep
        }
        //更新maxReachOneMoreStep
        if (nums[i] + i > maxReachOneMoreStep)
            maxReachOneMoreStep = nums[i] + i
    }
    return step
}
