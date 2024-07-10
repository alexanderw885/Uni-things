#!/bin/bash

mkdir files
cd files

end=init
end=10
for ((counter=init ; counter<end ; counter++))
do
	touch silver$counter
done
