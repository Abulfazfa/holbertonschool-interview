#!/usr/bin/node

const request = require('request');
const arg = process.argv[2];  // Get the Movie ID from the command-line argument
const url = `https://swapi-api.hbtn.io/api/films/${arg}`;  // API URL for the specific movie

// Function to recursively fetch and print character names
const charNames = (characters, i = 0) => {
  if (i === characters.length) return;  // Base case: when all characters are printed
  request(characters[i], (error, response, body) => {
    if (error) throw error;  // Handle any errors from the API request
    console.log(JSON.parse(body).name);  // Parse and print the character's name
    charNames(characters, i + 1);  // Recursively call the function for the next character
  });
};

// Request movie information from the API
request(url, (error, response, body) => {
  if (error) throw error;  // Handle any errors from the movie request
  const char = JSON.parse(body).characters;  // Extract the list of character URLs
  charNames(char);  // Call the function to print character names
});
