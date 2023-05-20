/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
// var throttle = function(fn, t) {
//   let timeout = null;
//   let nextTimeToCallFn = 0;
//   return function(...args) {
//     const delay = Math.max(0, nextTimeToCallFn - Date.now());
//     clearTimeout(timeout);
//     timeout = setTimeout(() => { 
//       fn(...args);
//       nextTimeToCallFn = Date.now() + t;
//     }, delay);
//   }
// };
// var throttle = function(fn, t) {
//   let intervalInProgress = null;
//   let argsToProcess = null;
  
//   const intervalFunction = () => {
//     if (argsToProcess === null) {
//       clearInterval(intervalInProgress);
//       intervalInProgress = null; // enter the waiting phase
//     } else {
//       fn(...argsToProcess);
//       argsToProcess = null;
//     }
//   };

//   return function throttled(...args) {
//     if (intervalInProgress) {
//       argsToProcess = args;
//     } else {
//       fn(...args); // enter the looping phase
//       intervalInProgress = setInterval(intervalFunction, t);
//     }
//   }
// };
var throttle = function(fn, t) {
  let timeoutInProgress = null;
  let argsToProcess = null;
  
  const timeoutFunction = () => {
    if (argsToProcess === null) {
      timeoutInProgress = null; // enter the waiting phase
    } else {
      fn(...argsToProcess);
      argsToProcess = null;
      timeoutInProgress = setTimeout(timeoutFunction, t);
    }
  };

  return function throttled(...args) {
    if (timeoutInProgress) {
      argsToProcess = args;
    } else {
      fn(...args); // enter the looping phase
      timeoutInProgress = setTimeout(timeoutFunction, t);
    }
  }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */