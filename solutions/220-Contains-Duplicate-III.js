//暴力求解
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    let length = nums.length 
    let end
    for(i=0;i<length;i++){
        end = i + k
        for(j=i+1;j<=end&&j<length;j++)
            if(Math.abs(nums[i]-nums[j])<=t) return true
    }
    return false
}

