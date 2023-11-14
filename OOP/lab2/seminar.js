class prima{
    constructor() {
        this.time = new Date()
    }
    afisare(){
        console.log(this.time)
    }

}

console.log('primu')
const primu = new prima()
primu.afisare()

class doilea{
    constructor(parametru) {
        this.parametru = parametru
        this.time = new Date()
    }
    afisare(){
        console.log(this.time)
        console.log(this.parametru)
    }
}
console.log('doilea')
const doi = new doilea(12)
doi.afisare()
