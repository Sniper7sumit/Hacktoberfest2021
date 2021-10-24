
let w = 'abx';
let S = 'abxaba';

// Split the word to get it in form of an array
let holdWords = S.split("");

// Loop through the array 
for(let i = 0; i < holdWords.length; i++) {
//     Take from current index to the lenght of that we are looking for its anagram
    let currWord = holdWords.slice(i,i + w.length).join("");
    
//     Split sort both words and compare if the match to know if it's an anagram
    if(currWord.split("").sort().join("") == w.split("").sort().join("")) {
//         Output current word if it's an anagram
        console.log("Current Word Is Anagram Of w")
        console.log(currWord);
    }
} 
