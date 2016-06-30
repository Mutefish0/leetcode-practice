/*计数排序*/
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


/*快速排序*/
//划分数组子程序
//返回一个q,使得A[p]到A[q-1]的值都小于A[q],而A[q+1]到A[r]的值都大于A[q]
function quick_sort_partion(A,p,r){
    let temp
    let radix = A[r]
    let i = p - 1
    let j = p - 1 
    while(++j<r){
        if(A[j]<radix){
            i ++
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
        } 
    }
    temp = A[i+1]
    A[i+1] = A[r]
    A[r] = temp
    return i + 1
}
//排序数组子程序
function quick_sort(A,p,r){
    if(p<r){
        let q = quick_sort_partion(A,p,r)
        quick_sort(A,p,q-1)
        quick_sort(A,q+1,r)
    }
}
//快速排序主程序
function QuickSort(A){
    quick_sort(A,0,A.length-1)
}

