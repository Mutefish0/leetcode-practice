//牛顿迭代法
var isPerfectSquare = function(num) {
    if(num===0||num===1) return true
    let set = {}
    let x = Math.floor(num/2)
    let y 
    while(1){
        y = x*x - num
        x = Math.floor(x - y/2/x)
        if(!set[y]) set[y] = 1
        else break;
    }
    if(y===0) return true
    else return false
}
//二分法
var isPerfectSquare = function(num) {
    let low = 0
    let high = num
    let mid = Math.ceil((low + high)/2)
    while(mid<high){
        let multiple = mid*mid
        if(multiple==num) return true
        else if(multiple<num) low = mid
        else if(multiple>num) high =mid
        mid = Math.ceil((low + high)/2)
    }
    if(mid*mid==num) return true
    else return false
}