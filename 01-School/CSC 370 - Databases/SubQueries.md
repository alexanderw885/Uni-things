can have queries within queries
anywhere you would put a relation, you could put a query instead
```sql
SELECT *
FROM Badges
Where Id < 50;
------ same as ------
SELECT *
FROM
(
   SELECT */ FROM Badges Where Id < 50
);
```

order that things are done often does not matter, results tend to be the same any way you perform the operations


#### IN / NOT IN
takes 1 dimensional relation as well as input
list + input
```sql
-- retrive all users who have not collected any badges *THIS YEAR*

SELECT COUNT(*)
FROM `Users`
WHERE `Id` NOT IN
(
  SELECT `UserId`
  FROM `Badges`
  WHERE `Date` >= '%2024-01-01%'
);
```
#### within FROM / JOIN clause
```sql
-- get the display name of all users who have collected the most popular badge
--DOES NOT WORK

SELECT `DisplayName`
FROM `Users`
JOIN 
-- most popular badge
(
  SELECT *
  from Badges
  GROUP BY Id
  ORDER BY COUNT(*) DESC
  LIMIT 1
) AS PopBadge
  on (Users.Id = PopBadge.UserId);
```

#### WHERE = 1x1 relation
when guaranteed to return only one value from subquery
