/**
 * @param {number[]} nums
 * @return {number}
 */
let maxSubArray = function(nums) {
    let length = nums.length
    if(length===1) return nums[0]
    let potential = []
    potential[-1] = 0
    let left = -1
    let right = 0
    let left_successor = -1
    let left_successor_min = 0
    for(i=0;i<length;i++){
        potential[i] = potential[i-1] + nums[i]
        if(potential[i]-left_successor_min>=potential[right]-potential[left]){
            left = left_successor
            right = i
        }
        else if(potential[i]>potential[right]) right = i 
        if(potential[i]<left_successor_min) {
            left_successor_min = potential[i]
            left_successor = i
        }
    }
    return potential[right]-potential[left]
}

