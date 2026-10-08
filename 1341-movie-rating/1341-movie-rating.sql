SELECT name AS results
FROM (
    SELECT u.name
    FROM MovieRating r
    JOIN Users u ON r.user_id = u.user_id
    GROUP BY r.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
) t1

UNION ALL

SELECT title AS results
FROM (
    SELECT m.title
    FROM MovieRating r
    JOIN Movies m ON r.movie_id = m.movie_id
    WHERE DATE_FORMAT(r.created_at, '%Y-%m') = '2020-02'
    GROUP BY r.movie_id, m.title
    ORDER BY AVG(r.rating) DESC, m.title ASC
    LIMIT 1
) t2;