#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Fetch movie data from the Star Wars API
request(url, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  // Function to fetch and print each character's name
  const printCharacter = (url, callback) => {
    request(url, (err, res, data) => {
      if (err) {
        console.error('Error:', err);
        return;
      }
      console.log(JSON.parse(data).name);
      callback();
    });
  };

  // Iterate over all character URLs
  const printAllCharacters = (i) => {
    if (i < characters.length) {
      printCharacter(characters[i], () => printAllCharacters(i + 1));
    }
  };

  printAllCharacters(0);
});
