type F = (x: number) => number;
// editorial solution
function compose(functions: F[]): F {
    return (x: number) => functions.reduceRight((acc, f) => f(acc), x);
}
;