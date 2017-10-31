/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
    if (s.length < 2) return s
    s = s.split('').join('#')
    var pos = 0, rl = [0], maxRight = 0, maxPos = 0, r 
    for (var i = 1; i < s.length; i++) {
        r = i < maxRight ? Math.min(rl[2*pos-i], maxRight-i) : 0
        while (i+r+1 < s.length && i-r-1 > -1 && s[i-r-1] == s[i+r+1]) r++
        rl[i] = r
        if (i+r >= maxRight) {
            pos = i
            maxRight = pos + rl[pos]
        }
        if (r > rl[maxPos] || r == rl[maxPos] && s[i+r] != '#') maxPos = i 
    }
    return s.slice(maxPos - rl[maxPos], maxPos + rl[maxPos] + 1).split('#').join('')
};