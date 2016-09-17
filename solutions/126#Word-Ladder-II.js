/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {Set} wordList
 *   Note: wordList is a Set object, see:
 *   https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
 * @return {string[][]}
 */
var findLadders = function(beginWord, endWord, wordList) {
    //节点列表，用于图的表示
    var begin = new Node(beginWord)
    var end = new Node(endWord)
    var nodeList = [begin,end]
    wordList.forEach(val => nodeList.push(new Node(val)))
    
    //构建图
    for(var i=0,len=nodeList.length;i<len;i++)
        nodeList[i].setNeighbors(nodeList)
    
    //BFS建立广度优先树（从end到begin建立，便于后面从begin到end添加路径）
    var queue = [end] 
    while(queue.length>0) {
        var head = queue.shift()
        //指向begin的节点出队，即所有从end到begin的最短路径已经建立
        if(head.val===begin.val) break  

        head.color = 'black'

        for(var i=0,len=head.neighbors.length;i<len;i++) {
            var node = head.neighbors[i]
            if(node.color==='white') {
                node.depth = head.depth + 1 
                node.color = 'gray'
                node.PIs.push(head)
                queue.push(node)
            }
            //不同于常规广度优先树，入队顺序不同而导致树不同，在此，PI属性是一个数组，可以指向多个节点
            //由于一个节点有多个父节点，建立起来的“树”其实已经不是树了
            else if(node.color==='gray'&&node.depth>head.depth) 
                node.PIs.push(head)
        }
    }
    
    var paths = []
    //用于表示path的节点
    queue = [{
        PIs: begin.PIs,     
        path: [begin.val]   
    }]
    //还是广度优先,收集所有路径
    while(queue.length>0) {
        var head = queue.shift()

        if(head.PIs.length===0) {
            if(head.path.length>=2)
                paths.push(head.path)
        }
        else{
            for(var i=0,len=head.PIs.length;i<len;i++) {
                var PI = head.PIs[i]
                queue.push({
                    PIs: PI.PIs,
                    path: head.path.concat([PI.val])
                })
            }
        }
    }

     return paths
};

class Node{
    constructor(val) {
        this.val = val
        this.neighbors = []
        this.color = 'white'
        this.depth = 1
        this.PIs = []
    }
    //设置邻居
    setNeighbors(nodeList) {
        for(var i=0,len=nodeList.length;i<len;i++) {
            if(isNeighbor(this.val,nodeList[i].val))
                this.neighbors.push(nodeList[i])
        }
    }
}

/**
 * 判断两个词是否只有一个字母不同(位置不改变)
 * @param  {String}  wordA 
 * @param  {String}  wordB 
 * @return {Boolean}   
 */
function isNeighbor(wordA,wordB) {
    var changed = false
    for(var i=0,len=wordA.length;i<len;i++) {
        if(wordA[i]!=wordB[i]){
            if(changed) return false
            else changed = true 
        }
    }
    return changed
}
