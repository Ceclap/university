const cr = 2117
const pix = 347
let cont = true
let x = 0

while(cont)
{
    x++
    console.log(x)
    if(pix * 3 === cr)
        cont = false
}
console.log(x)