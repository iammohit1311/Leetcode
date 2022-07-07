// { Driver Code Starts
//Initial Template for javascript


'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let a=readLine().trim().split(" ").map((x) => parseInt(x));
        let key = parseInt(readLine());
        let obj = new Solution();
        let res = obj.findIndex(a,n,key);
        let s = "";
        for(let it of res){
            s+=it+" ";
        }
        console.log(s);
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} a
 * @param {number} n
 * @param {number} key
 * @return {number[]}
*/

class Solution {
    findIndex(a,n,key){
       //code here
       let result = [];
       
       for(let i=0; i<n; i++){
           if(a[i] === key) result.push(i);
           // result = [5, 5]
       }
       
       if(result.length > 2)
        result = [result[0], result[result.length-1]];
    
       if(result.length === 1)
        result = [result[0], result[0]];
        
       if(result.length === 0)
        result = [-1, -1];
        
        return result;
    }
}
