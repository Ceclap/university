class object{
    constructor(producator, procesor, frecventa, memorieOperativa, memorieDisc) {
        this.producator = producator
        this.procesor = procesor
        this.frecventa = frecventa
        this.memorieOperativa = memorieOperativa
        this.memorieDisc = memorieDisc
    }

    modify(producator, procesor, frecventa, memorieOperativa, memorieDisc){
        this.producator = producator
        this.procesor = procesor
        this.frecventa = frecventa
        this.memorieOperativa = memorieOperativa
        this.memorieDisc = memorieDisc
    }
}

const saveButton = document.getElementById('saveButton');

const comparareButton = document.getElementById('comparareButton');

const modifyButton = document.getElementById('modifyButton');

const sort = document.getElementById('sortButton');



const computer = []

saveButton.addEventListener('click', ()=>{
    const producator = document.querySelector('.saveproducator').value;
    const procesor = document.querySelector('.saveprocesor').value;
    const frecventa = parseInt(document.querySelector('.savefrecventa').value);
    const memorieOperativa = document.querySelector('.savememorieOperativa').value;
    const memorieDisc = document.querySelector('.savememorieDisc').value;

    const element = new object(producator, procesor, frecventa, memorieOperativa, memorieDisc)
    computer.push(element)
    console.log(computer)
})

comparareButton.addEventListener('click', ()=>{
    const producator = document.querySelector('.comparare').value;
    const filtrat = computer.filter((element)=>element.producator === producator)
    console.log(filtrat)
})

modifyButton.addEventListener('click', ()=>{
    const oldproducator = document.querySelector('.oldproducator').value;
    const oldprocesor = document.querySelector('.oldprocesor').value;
    // const oldfrecventa = parseInt(document.querySelector('.oldfrecventa').value);
    // const oldmemorieOperativa = document.querySelector('.oldmemorieOperativa').value;
    // const oldmemorieDisc = document.querySelector('.oldmemorieDisc').value;

    const producator = document.querySelector('.newproducator').value;
    const procesor = document.querySelector('.newprocesor').value;
    const frecventa = parseInt(document.querySelector('.newfrecventa').value);
    const memorieOperativa = document.querySelector('.newmemorieOperativa').value;
    const memorieDisc = document.querySelector('.newmemorieDisc').value;


    const oldComputer = computer.find((element)=> element.producator === oldproducator && element.procesor === oldprocesor)
    oldComputer.modify(producator, procesor, frecventa, memorieOperativa, memorieDisc)
    console.log(computer)
})


sort.addEventListener('click', ()=>{
    computer.sort((a,b)=>a.frecventa-b.frecventa)
    console.log(computer)
})




