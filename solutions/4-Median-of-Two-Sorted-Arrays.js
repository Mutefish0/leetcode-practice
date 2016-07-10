/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
 // 时间复杂度 (m+n)/2
var findMedianSortedArrays = function(nums1, nums2) {
    let l  = nums1.length + nums2.length
        lm   = Math.floor(l/2) + 1,
        nums = [],
        p1   = 0,
        p2   = 0
    for(let i=0;i<lm;i++){
        if(nums2[p2]===undefined||nums1[p1]<nums2[p2])
            nums.push(nums1[p1++])
        else
            nums.push(nums2[p2++])
    }
    return (nums[Math.ceil((l-1)/2)]+nums[Math.floor((l-1)/2)])/2
}