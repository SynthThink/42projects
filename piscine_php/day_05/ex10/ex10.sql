SELECT title AS "Title", summary AS "Summary", prod_year
FROM film
INNER JOIN genre
WHERE genre.id_genre = film.id_genre and genre.name = 'erotic'
ORDER BY prod_year DESC;
