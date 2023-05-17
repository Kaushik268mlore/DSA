/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise((resolve) => {
        let inProgressCount = 0;
        let functionIndex = 0;
        function helper() {
            if (functionIndex >= functions.length) {
                if (inProgressCount === 0) resolve();
                return;
            }

            while (inProgressCount < n && functionIndex < functions.length) {
                inProgressCount++;
                const promise = functions[functionIndex]();
                functionIndex++;
                promise.then(() => {
                    inProgressCount--;
                    helper();
                });
            }
        }
        helper();
    });
};
// var promisePool = async function(functions, n) {
//     async function evaluateNext() {
//         if (functions.length === 0) return;
//         const fn = functions.shift();
//         await fn();
//         await evaluateNext();
//     }
//     const nPromises = Array(n).fill().map(evaluateNext);
//     await Promise.all(nPromises);
// };
// var promisePool = async function(functions, n) {
//     const evaluateNext = () => functions[n++]?.().then(evaluateNext);
//     return Promise.all(functions.slice(0, n).map(f => f().then(evaluateNext)));
// };
/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */