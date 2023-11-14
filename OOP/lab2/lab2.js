class Document{
    constructor(denumire, tema, autor, pagini){
        this.denumire = denumire
        this.tema = tema
        this.autor = autor
        this.pagini = pagini
        this.time = new Date
    }
    modify(tema){
        this.tema = tema
        this.time = new Date
    }
}

const World = new Document('laborator2', 'laborator', 'Ion Creanga', '20')
console.log(World)
World.modify('lab3')
console.log(World)

