//二叉搜索树
class BinarySearchTree{
    constructor(){
        this.root = null
    }
    //插入的节点必须包含关键字key
    insert(node){
        let key = node.key
        if(key){
            node.left = null
            node.right = null
            let p_last = null
            let p = this.root
            while(p){
                p_last = p
                if(key<p.key) p = p.left
                else p = p.right
            }
            node.parent = p_last
            if(!p_last) this.root = node
            else if(key<p_last.key) p_last.left = node
            else p_last.right = node
        }
    }
    //通过关键字查找节点
    search(key){
        let p = this.root
        while(p&&key!=p.key){
            if(key<p.key) p = p.left
            else p = p.right
        }
        return p
    }
    //中序遍历(得到关键字按从小到大的顺序的结果)
    static _inorderWalk(root,procedure){
        if(root){
            BinarySearchTree._inorderWalk(root.left,procedure)
            procedure.delegate(root,procedure.index++)
            BinarySearchTree._inorderWalk(root.right,procedure)
        }
    }
    //中序遍历
    inorderWalk(delegate){
        BinarySearchTree._inorderWalk(this.root,{delegate:delegate,index:0})
    }
    //查找最小子节点
    static _minimum(root){
        let p = root
        while(p.left) p = p.left
        return p
    }
    //查找后继,(按中序遍历的顺序，既关键字大于他的最小的节点)
    //如果右子树不为空，则只需找到右子树的最小节点
    //如果右子树为空，则后继为最底层的祖先，且该节点属于后继的左子树
    static successor(node){
        if(node.right) return BinarySearchTree._minimum(node.right)
        let ancestor = node
        while(ancestor.parent&&ancestor.parent.left!=ancestor) ancestor = ancestor.parent
        return ancestor.parent
    }
    //删除指定关键字的节点
    //用目标子树代替源子树
    static _transplant(T,source,target){
        if(!source.parent) T.root = target
        else if(source.parent.left==source) source.parent.left = target
        else source.parent.right = target
        if(target) target.parent = source.parent
    }
    //删除节点
    delete(nodeOrKey){
       let node 
       if(typeof(nodeOrKey)==='number') node = this.search(nodeOrKey)
        else node = nodeOrKey
        if(node&&node.key){
            if(!node.left) BinarySearchTree._transplant(this,node,node.right)
            else if(!node.right) BinarySearchTree._transplant(this,node,node.left)
            else{
                let successor = BinarySearchTree._minimum(node.right)
                if(successor.parent!=node){
                    BinarySearchTree._transplant(this,successor,successor.right)
                    successor.right = node.right
                    node.right.parent = successor
                } 
                BinarySearchTree._transplant(this,node,successor)
                successor.left = node.left
                successor.left.parent = successor
            }
            return node
        }
        else return null
    }
}

let bst = new BinarySearchTree()
bst.insert({key:2,data:'love'})
bst.insert({key:1,data:'i'})
bst.insert({key:3,data:'u'})
bst.delete(1)
bst.inorderWalk((node,index)=>{
    console.log(`${index}:${node.data}`)
})