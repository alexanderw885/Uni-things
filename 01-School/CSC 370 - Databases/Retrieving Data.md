INTO TABLE 'given you have files in downloads
```SQL
create database `class-movielens`
use class-movielens;
//make table tags
LOAD DATA LOCAL INFILE 'C:\Users\alexa\Downloads\ml-latest-small\tags.csv'
    -> INTO TABLE `tags`
    -> FIELDS TERMINATED BY ','
    -> ENCLOSED BY '"'
    -> LINES TERMINATED BY '\r\n'
    -> IGNORE 1 ROWS;
```
On one line:
```SQL
LOAD DATA LOCAL INFILE 'C:\Users\alexa\Downloads\ml-latest-small\TAGS' INTO TABLE `tags` FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATE
D BY '\r\n' IGNORE 1 LINES;
```
by default you can't load files from local for security reasons
first, change security for this session
```SQL
SET GLOBAL local_infile=1;
```
only need to once
**and** when logging into mysql via command line
```powershell
mysql --local-infile=1 -u root -p
```
(if on non-windows, use sudo first)