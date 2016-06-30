var topKFrequent = function(nums,k){
    let length = nums.length
    let map = {}
    let ret = []
    for(let i=0;i<length;i++)
        if(map[nums[i]]) map[nums[i]] ++
        else map[nums[i]] = 1
    let keys = []
    for(let key in map) keys.push(key)
    keys.sort((key1,key2)=>map[key2]-map[key1])
    for(let i=0;i<k;i++) ret.push(+keys[i])
    return ret
}