/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        n+=1;
        return n-1;
    };
};
// Overview
// This question is intended as an introduction to closures. In JavaScript, functions have a reference to all variables declared in the same scope as well as any outer scopes. These scopes are known as the function's lexical environment. The combination of the function and it's environment is known as a closure.

// Closure Example
// In Javascript, you can declare functions within other functions and return them. The inner function has access to any variables declared above it.

// function createAdder(a) {
//   return function add(b) {
//     const sum = a + b;
//     return sum;
//   }
// }
// const addTo2 = createAdder(2);
// addTo2(5); // 7
// The inner function add has access to a. This allows the outer function to serve as a factory of new functions, each with different behavior.

// Closures Versus Classes
// You may notice that in the above example createAdder is very similar to a class constructor.

// class Adder {
//   constructor(a) {
//      this.a = a;
//   }

//   add(b) {
//     const sum = this.a + b;
//     return sum;
//   }
// }
// const addTo2 = new Adder(2);
// addTo2.add(5); // 7
// Besides differences in syntax, both code examples essentially serve the same purpose. They both allow you to pass in some state in a "constructor" and have "methods" that access this state.

// One key difference is that closures allow for true encapsulation. In the class example, there is nothing stopping you from writing addTo2.a = 3; and breaking it's expected behavior. However, in the closure example, it is theoretically impossible to access a. Note that as of 2022, true encapsulation is achievable in classes with # prefix syntax.

// Another difference is how the functions are stored in memory. If you create many instances of a class, each instance stores a single reference to the prototype object where all the methods are stored. Whereas for closures, all the "methods" are generated and a "copy" of each is stored in memory each time the outer function is called. For this reason, classes can be more efficient, particularly in the case where there are many methods.

// Unlike in languages like Java, you will tend to see code written with functions rather than with classes. But since JavaScript is a multi-paradigm language, it will depend on the particular project you are working on.

// Approach 1: Increment Then Return
// We declare a variable currentCount and set it equal to n - 1. Then inside the counter function, increment currentCount and return the value. Note that since currentCount is modified, it should be declared with let rather than const.

// Implementation
// var createCounter = function(n) {
//   let currentCount = n - 1;
//   return function() {
//     currentCount += 1;
//     return currentCount;      
//   };
// };

// Approach 2: Postfix Increment Syntax
// JavaScript provides convenient syntax that returns a value and then increments it. This allows us to avoid having to initially set a variable to n - 1.

// Implementation
// var createCounter = function(n) {
//   return function() {
//     return n++;      
//   };
// };

// Approach 3: Prefix Decrement and Increment Syntax
// JavaScript also has syntax that allows you to increment a value and then return it. Because the increment happens before the value is returned, we must first decrement the value initially similar to Approach 1.

// Implementation
// var createCounter = function(n) {
//   --n;
//   return function() {
//     return ++n;      
//   };
// };

// Approach 4: Postfix Increment Syntax With Arrow Function
// We can reduce the amount of code in Approach 2 by using an arrow function with an implicit return.

// Implementation

// var createCounter = function(n) {
//   return () => n++;
// };
/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */