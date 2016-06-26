
function CountingSort(A,k){
    let length = A.length
    let C = []
    let B = []
    for(i=0;i<=k;i++) C[i] = 0
    for(i=0;i<length;i++) C[A[i]] += 1
    for(i=1;i<=k;i++) C[i] = C[i-1] + C[i]
    for(i=0;i<length;i++){
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1
    }
    return B
}

var topKFrequent = function(nums, k) {
    let length = nums.length
    let kvm = new Puremap()
    kvm.setDuplicate((value,oldValue)=>oldValue+1)
    for(i=0;i<length;i++) kvm.push(nums[i],1)

    let max_frq = 1
    for(i=0;i<kvm.length;i++) if(kvm.values[i]>max_frq) max_frq = kvm.values[i]
    let vkm = kvm.produce()
    let rankedFrq = [] 
    Object.assign(rankedFrq,vkm.keys)
    rankedFrq = CountingSort(rankedFrq,max_frq)

    let ret = []
    for(i=1;i<=k&&i<=vkm.length;i++){
        ret = ret.concat(vkm.entry[rankedFrq[vkm.length-i]])
    }
    while(ret.length>k) ret.pop()
    return ret 
}
