/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
// so basically I've to create a resolve or a reject promise , and then call the method on a promise.race which takes an array of arguments 
// var timeLimit = function(fn, t) {
// 	return async function(...args) {
//         const timout=new Promise((resolve,reject)=>{
//              setTime=setTimeout(()=>{
//             reject("Time Limit Exceeded")
//              }
//                                ,t)
//         })
//         return Promise.race(fn(...args),timeout);
//     } 
var timeLimit = function(fn, t) {
	return async function(...args) { 
        return new Promise((resolve,reject)=>{
            setTimeout(()=>{ reject("Time Limit Exceeded")},t)
            fn(...args).then(res=>{
                resolve(res);
            }).catch(reject);
        })
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */