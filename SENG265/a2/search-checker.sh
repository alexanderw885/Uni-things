#!/bin/bash

echo 'test1'
cat search-tests/input01/query01.txt |./search.py search-tests/index01 |diff search-tests/output01/ranking01.txt -
echo 'test2'
cat search-tests/input01/query02.txt |./search.py search-tests/index01 |diff search-tests/output01/ranking02.txt -
echo 'test3'
cat search-tests/input01/query03.txt |./search.py search-tests/index01 |diff search-tests/output01/ranking03.txt -
echo 'test4'
cat search-tests/input02/query04.txt |./search.py search-tests/index02 |diff search-tests/output02/ranking04.txt -
echo 'test5'
cat search-tests/input02/query05.txt |./search.py search-tests/index02 |diff search-tests/output02/ranking05.txt -
echo 'test6'
cat search-tests/input02/query06.txt |./search.py search-tests/index02 |diff search-tests/output02/ranking06.txt -
echo 'test7'
cat search-tests/input02/query07.txt |./search.py search-tests/index02 |diff search-tests/output02/ranking07.txt -
