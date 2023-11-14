class Triunghi{
    constructor(latura1,latura2,latura3) {
        this.latura1 = latura1
        this.latura2 = latura2
        this.latura3 = latura3
    }

    perimetru(){
       return  this.latura1+this.latura2+this.latura3
}

    afisare(){
        console.log('latura1:'+this.latura1)
        console.log('latura2:'+this.latura2)
        console.log('latura3:'+this.latura3)
    }
}

const Marcel = new Triunghi(1,2,3)

console.log(Marcel.perimetru());
console.log(Marcel.afisare())