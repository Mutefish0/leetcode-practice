function Measurer(delegate){
    let startTime = (new Date()).getTime()
    console.log()
    delegate()
    let endTime = (new Date()).getTime()
    console.log(`Prog finished,${endTime-startTime} ms passed`)
}
