function Measurer(delegate){
    let startTime = (new Date()).getTime()
    console.log()
    delegate()
    let endTime = (new Date()).getTime()
    console.log(`Prog finished,${endTime-startTime} ms passed`)
}
//打乱数组的顺序
function randomize(array){
    array.sort((a,b)=>Math.random()-0.5)
}
