class Puremap{
    constructor(){
        this.keys = []
        this.values = []
        this.entry = {}
        this.length = 0
        this.key_index = {}
    }
    setDuplicate(duplicate){
        this.duplicate = duplicate
    }
    push(key,value){
        if(this.entry[key]===undefined) {
            this.entry[key] = value
            this.keys.push(key)
            this.values.push(value)
            this.key_index[key] = this.length
            this.length += 1
        }
        else if(this.duplicate){
            let newValue = this.duplicate(value,this.entry[key])
            this.entry[key] = newValue
            this.values[this.key_index[key]] = newValue
        }
    }
    produce(){
        let ret = new Puremap()
        ret.setDuplicate((value,oldValue)=>{
            oldValue.push(value[0])
            return oldValue
        })
        for(let i=0;i<this.length;i++)
            ret.push(this.values[i],[this.keys[i]])
        ret.setDuplicate(null)
        return ret 
    }
}

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
