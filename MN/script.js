const findRootInterval = (func, a, b, epsilon) => {
    let fa = func(a);
    let fb = func(b);

    if (fa * fb >= 0) {
        throw new Error("Funcția nu schimbă semnul pe intervalul dat.");
    }

    let contor = 0
    while ((b - a) > epsilon) {
        contor++
        let c = (a + b) / 2;
        let fc = func(c);

        if (fc === 0) {
            return [c, c];
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    console.log(contor)
    return [a, b];
}

function f(x) {
    return  Math.sqrt(x+1)-1/x
}

try {
    let [a, b] = findRootInterval(f, 0, 100, 0.0001);
    console.log(`Intervalul în care se află rădăcina este [${a}, ${b}]`);
} catch (error) {
    console.error(error.message);
}
