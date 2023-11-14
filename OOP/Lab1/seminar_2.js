class Masina{
    constructor(consum, motorina) {
        this.consum = consum
        this.motorina = motorina
    }
    alimentare(litrii){
        this.motorina += litrii
        console.log(this.motorina)
    }
    merge(distanta){
        if(this.motorina/this.consum < distanta/100)
        {
            console.log('masina nu va ajunge la destinatie')
        }
        else{
            this.motorina -= this.consum * distanta/100
            console.log(this.motorina)
        }
    }
}

const dacia = new Masina(7.1,100)
dacia.alimentare(10)
dacia.merge(100)