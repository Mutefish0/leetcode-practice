/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let length = s.length
    let l = 0
    let r = 0
    let max = 0
    let map = {}
    for(;r<length&&max<length-l;r++){
        if(map[s[r]]>=l){
            if(r-l>max) max = r-l
            l = map[s[r]] + 1
        }
        map[s[r]] = r
    }
    if(r-l>max) max = r-l
    return max
}
