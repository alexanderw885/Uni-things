-- Code provided to students in UVic CSC 330 Spring 2025
-- 
-- Author: Mike Zastre
--
-- The copyright for this code is held by Mike Zastre. It is
-- not to be uploaded or otherwise accessed by any online service
-- or online-facilitated tool (such as Copilot or ChatGPT, although
-- this list is no exhaustive).


import System.IO
import System.Environment (getArgs)
import Data.List
import Text.Read (Lexeme(String))

type ProblemTuple = (Integer, [Integer])


-- Top level function: Because Haskell constrains the mixture of
-- of functions having I/O with functions having no I/O, we need
-- to use an IO monad (the "IO ()" syntax).  There should be no
-- need to modify this code unless you _really_ know what you are
-- doing in Haskell.  This has been written for you in order that
-- you may completely ignore I/O issues.
--
-- The first parameter if `stamps` is the name of the input file;
-- the second is the name of the output file.
--
-- THERE SHOULD BE NO NEED TO MODIFY THE CODE UP TO THE POINT
-- WITH THE COMMENT "-- STUDENT WORK BEGINS HERE".
--

main :: IO ()
main = do
    args <- getArgs
    case args of
        (inFile : outFile : _) -> stamps inFile outFile
        _ -> putStrLn "Usage: <input file> <output file>"

stamps :: String -> String -> IO ()
stamps inName outName = do
    inFile <- openFile inName ReadMode
    outFile <- openFile outName WriteMode
    lineData <- hGetContents inFile
    let rawLines = lines lineData
    let problemList = parseData rawLines
    let answers = process problemList
    outputResults outFile answers
    hClose inFile
    hClose outFile

parseData :: [String] -> [ProblemTuple]
parseData [] = []
parseData (a:[])
    | a == "0"  = []
    | otherwise = [(-1, [])]
parseData (a:b:as) = (width, stamps) : parseData as
    where
        width = read a :: Integer
        stamps = string2ints (words b)

string2ints :: [String] -> [Integer]
string2ints [] = []
string2ints (a:as) = (read a :: Integer) : string2ints as

ints2string :: [Integer] -> String
ints2string [] = ""
ints2string (a:[]) = show a
ints2string (a:as) = show a ++ " " ++ ints2string as

outputResults :: Handle -> [String] -> IO ()
outputResults _ [] = return ()
outputResults outFile (a:as) = do
    hPutStrLn outFile a
    outputResults outFile as



--
-- STUDENT WORK BEGINS HERE
--
-- YOU ARE FORBIDDEN TO USE EITHER "do" OR "let" IN YOUR
-- SOLUTION. THE APPEARANCE OF EITHER OF THESE KEYWORDS
-- IN YOUR CODE MAY RESULT IN A FAILING GRADE FOR THIS PART
-- OF THE ASSIGNMENT.
--

-- Entry point to solving the assignment question. 
-- process function takes a list of problem tuples, processes the head, then
-- recursively calls itself on the tail of the problem tuple list.(*)
-- In each iteration, it calls getSequence on the head problem tuple to get the longest sequence
-- of possible values, and then adds that along with the list of stamps
process :: [ProblemTuple] -> [String]
process = map findMaxCoverage
    where
        findMaxCoverage :: ProblemTuple -> String
        findMaxCoverage (m, x:xs) =
            "max coverage = " ++ show (length result - 1) ++ " :" ++ printDenominations xs
          where
            result = takeWhile (<= m) $
                    0 : [minimum [ 1 + result !! fromIntegral (y - c) | c <- xs, y - c >= 0]
                    | y <- [1..]
                    ]
printDenominations :: [Integer] -> String
printDenominations = concatMap (\x -> " " ++ show x)

-- takeWhile: takes a predicate, and a list. 
-- the predicate, in this case (<= m), is evaluated on each value in the list
-- takeWhile returns all values from the list UP TO the first value that does not satisfy the predicate.

takeWhileFunc :: ProblemTuple -> [Integer]
takeWhileFunc (m, x:xs)
   = result 
      where
        result = takeWhile (<= m) $ 
           0 : [minimum [ 1 + result !! fromIntegral (y-c) | c <- xs, y - c >= 0]
           | y <- [1..]
           ]

-- takeWhile is doing dynamic programming, it's essentially using inductive reasoning to get
-- the number of stamps used for each value. The target value is the list index, and the 
-- number of stamps is the value in the list

-- let's go one step deeper, just looking at the list inside takeWhile. In order to not get stuck in an infinite 
-- loop, we'll have to set a limit to y

innerList :: ProblemTuple -> [Integer]
innerList (m, x:xs )= result 
   where
    result = 0 : [minimum [ 1 + result!!(fromIntegral(y-c)) | c <- xs, y - c >= 0]
     | y <- [1..m * maximum xs]
     ]

-- the outer "loop"/ list comprehension on y, fills the same role as my getSequence function, 
-- it passes values it wants to reach into the inner loop. 

-- The inner loop is doing the inductive/dynamic step. It's looking at previously computed min stamps,
-- ones that are a single stamps worth away from our target value, and adds one to the smallest value. 

-- for example, let's go through the tuple (3, [1,4]). our base case is 0, so the zeroth index is set to zero. [0]
-- then the value at index 1 = 1 + min(index(1-1),index(1-4)). We ignore 1-4, and the value at index (1-1) = 0, 
-- so index 1 = 1 + 0. [0, 1]
-- index 2 = 1 + min(index(2-1), index(2-4)), = 1 + index(2-1) = 1 + 1 = 2   [0,1,2]
-- index 3 = 1 + min(index (3-1), index(3-4)), = 1 + index(3-1) = 1 + 2 = 3   [0,1,2,3]
-- from this point on, we won't get any indices below zero, so we need to use the min functionKey
-- index 4 = 1 + min(index(4-1), index(4-4)) = 1 + min(3, 0) = 1+0 = 1       [0,1,2,3,1]
-- index 5 = 1 + min(index(5-1), index(5-4)) = 1 + (1, 1) = 1 + 1 = 2        [0,1,2,3,1,2]
-- and so on


-- All takeWhile is doing is stopping the list from being evaluated past the point where it takes more than m stamps.


-- ___________________________________
-- Example tuples

pt00 :: ProblemTuple
pt00 = (5, [4,1,4,12,21])

pt01 :: ProblemTuple
pt01 = (5, [2,1,4])

pt0 :: [ProblemTuple]
pt0 = [(5, [2, 1, 4])]

pt1 :: [ProblemTuple]
pt1 = [(5, [4, 1, 4, 12, 21]),
       (10, [5, 1, 7, 16, 31, 88]),
       (6, [4, 1, 5, 7, 8])
      ]

pt7a :: ProblemTuple
pt7a = (4, [5,1,5,11,21,31])

pt16 :: ProblemTuple
pt16 = (8,[6,1,7,21,91,101,111])