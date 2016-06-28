function Measurer(delegate){
    let startTime = (new Date()).getTime()
    console.log()
    delegate()
    let endTime = (new Date()).getTime()
    console.log(`Prog finished,${endTime-startTime} ms passed`)
}

//return new array 
//数组A中的所有元素必须大于零小于或等于k且是是整数
function CountingSort(A,k){
    let length = A.length
    let C = []
    let B = []
    for(i=0;i<=k;i++) C[i] = 0
    for(i=0;i<length;i++) C[A[i]] += 1
    for(i=1;i<=k;i++) C[i] = C[i-1] + C[i]
    for(i=length-1;i>=0;i--){
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1
    }
    return B
}

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
