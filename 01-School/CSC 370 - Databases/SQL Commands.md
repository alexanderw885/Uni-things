select:
choose categories in table
```SQL
select `rating`, `timestamp` from `tablename` ORDER BY `rating` DESC, `timestamp` DESC limit 10;
```
WHERE
select only where value = x
```SQL
select `rating`, `timestamp` from `tablename` WHERE `rating` = 4 limit 10;
```

select from multiple tables
```SQL
select DISTINCT `user_id`, `tag` from `tags`, `movies` where `movies`.`movie_id` = `tags`.`movie_id` limit 5;
```
used DISTINCT to remove duplicates

another way to do it
```SQL
select DISTINCT `tag`, `title`
->FROM `tags` AS `T`
-> JOIN `movies` AS `M`
-> ON (`T`.`movie_id` = `M`.`movie_id`);
->LIMIT = 5
```
these both do the same thing, but the bottom one is clearer

but what about strings?
```SQL
select DISTINCT `genres`
->FROM `movies`
->WHERE NOT `genre` LIKE '%|%';
```
LIKE is for string matching, % is the escape character
so '%|%' is read as '|'
LIKE gives a match as long as compare appears anywhere in the string