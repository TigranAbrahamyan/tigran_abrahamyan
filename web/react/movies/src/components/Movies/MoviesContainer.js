import React from 'react';
import _ from 'lodash';

import { Movies } from './Movies';
import { movies } from '../../movies';

export const MoviesContainer = () => {
  const [ moviesList, setMoviesList ] = React.useState(movies);
  const [ filteredMovies, setFilteredMovies ] = React.useState([]);
  const [ modalVisibility, setModalVisibility ] = React.useState(false);
  const [ moviesCount, setMoviesCount ] = React.useState(0);
  const [ searchValue, setSearchValue ] = React.useState('');
  const [ description, setDescription ] = React.useState('');
  const [ name, setName ] = React.useState('');

  React.useEffect(() => {
    const debounceFn = _.debounce(() => {
      setFilteredMovies(moviesList.filter((movie) => movie.name.toLowerCase().startsWith(searchValue.toLowerCase())));
    }, 1000);

    debounceFn();

    return () => debounceFn.cancel();
  }, [ searchValue ]);

  React.useEffect(() => {
    setFilteredMovies(moviesList);
    setMoviesCount(moviesList.length);
  }, [ moviesList ]);

  const handleModalVisibility = (state) => {
    setModalVisibility(state);
    setSearchValue('');
    setName('');
    setDescription('');
  };

  const addMovie = () => {
    if (!name || !description) {
      alert('Inputs is required');
    } else {
      const newMovie = { id: Date.now(), name, description, img: '/images/test.webp' };
      setMoviesList([ ...moviesList, newMovie ]);
      handleModalVisibility(false);
    }
  };

  const deleteMovie = (id) => {
    setMoviesList(moviesList.filter((movie) => movie.id !== id));
    setSearchValue('');
  };

  return (
    <Movies
      searchValue={searchValue}
      setSearchValue={setSearchValue}
      name={name}
      setName={setName}
      description={description}
      setDescription={setDescription}

      movies={filteredMovies}
      moviesCount={moviesCount}
      modalVisibility={modalVisibility}
      addMovie={addMovie}
      deleteMovie={deleteMovie}
      handleModalVisibility={handleModalVisibility}
    />
  );
}