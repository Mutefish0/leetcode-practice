var canMeasureWater = function(x, y, z) {
    if(z===0||z==x||z==y) return true
    let big = x > y ? x : y
    if(big===0) return false
    let small = x + y - big
    let start
    let r = small % big
    if(r==z||r+small==z||(r<=small&&r+big==z)) return true
    start = r
    let by = small + r
    do{
        r = by % big
        if(r==z||r+small==z||(r<=small&&r+big==z)) return true
        by = small + r
    }
    while(r!=start)
    return false
}