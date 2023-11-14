const recursie = (n) =>{
    if(n<2) {
        it1 = it1 + 3;
        return n;
    }
    return recursie(n-1) + recursie(n-2)
}




const fib2 = (n) =>{
    let i = 1
    let j = 0
    for(let k = 1; k<=n; k++)
    {
        j = i+j;
        i = j-i;
    }
    it2 = it2 + n

    return j
}

const fib3 = (n) =>{
    let phi = (1 + Math.sqrt(5)) / 2;
    let result = Math.round(Math.pow(phi, n) / Math.sqrt(5));
    it3 = it3 + 1
    return result;
}

const n = 100


let it1 = 0
console.log('Recursie')
const start1 = new Date()
// console.log(`Numarul Fiboncai${recursie(n)} iteratii ${it1}`);
// const end1 = new Date()
// console.log(end1-start1)

let it2 = 0
console.log('Fib 2')
const start2 = new Date()
console.log(`Numarul Fiboncai${fib2(n)} iteratii ${it2}`);
const end2 = new Date()
console.log(end2-start2)

let it3 = 0
console.log('fib3')
const start3 = new Date()
console.log(`Numarul Fiboncai${fib3(n)} iteratii ${it3}`);
const end3 = new Date()
console.log(end3-start3)
