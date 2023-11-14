class Matrix{

    constructor(row, col) {
        if(col === undefined)
        {
            this.row = row
            this.col = row
            this.matrix = [[this.row][this.col]]
        }else{
            this.row = row
            this.col = col
            this.matrix = [[this.row][this.col]]
        }
    }
    completare(num){
        this.matrix.push(...num)
    }
    show(){
        this.matrix.shift()
        console.log(this.matrix)
    }
    minus(matrix){
        matrix.map((el,index)=>{
            console.log(el-this.matrix[index])
        })
    }
    plus(matrix){
        matrix.map((el,index)=>{
            console.log(el+this.matrix[index])
        })
    }
    inmultirea(numar){
        this.matrix.map((el,index)=>{
            console.log(el*numar)
        })
    }



}
const patrat = new Matrix(4)
patrat.completare([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16])
patrat.show()
console.log('minus');
patrat.minus([1,2,3])
console.log('plus');
patrat.plus([1,2,3])
console.log('inmultirea')
patrat.inmultirea(10)