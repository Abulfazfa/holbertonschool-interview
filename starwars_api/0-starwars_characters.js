#!/usr/bin/node

const request = require('request');
const arg = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${arg}`;

const charNames = (characters, i = 0) => {
  if (i === characters.length) return;
  request(characters[i], (error, response, body) => {
    if (error) throw error;
    // Convert a string of characters JSON to a JavaScript object and print it
    console.log(JSON.parse(body).name);
    // Call recursively the function charNames and increment it to pass to the next character
    charNames(characters, i + 1);
  });
};

// Request to the API to recover movie information
request(url, function (error, response, body) {
  if (error) throw error;
  // Extract URL of characters from the body JSON response and store it in a var char
  const char = JSON.parse(body).characters;
  // Call the function charNames to print the characters
  charNames(char);
});