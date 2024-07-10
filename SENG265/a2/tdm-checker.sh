#!/bin/bash


rm -r output
echo "checking in01 without existing output"
./tdm-generator.py tdm-tests/input01 output
diff tdm-tests/output01/sorted_documents.txt output/sorted_documents.txt
diff tdm-tests/output01/sorted_terms.txt output/sorted_terms.txt
diff tdm-tests/output01/td_matrix.txt output/td_matrix.txt
echo "done checking in01 without existing output"
echo "checking in01 with existing output"
./tdm-generator.py tdm-tests/input01 output
diff tdm-tests/output01/sorted_documents.txt output/sorted_documents.txt
diff tdm-tests/output01/sorted_terms.txt output/sorted_terms.txt
diff tdm-tests/output01/td_matrix.txt output/td_matrix.txt
echo "done checking in01 with existing output"

rm -r output
echo "checking in02 without existing output"
./tdm-generator.py tdm-tests/input02 output
diff tdm-tests/output02/sorted_documents.txt output/sorted_documents.txt
diff tdm-tests/output02/sorted_terms.txt output/sorted_terms.txt
diff tdm-tests/output02/td_matrix.txt output/td_matrix.txt
echo "done checking in02 without existing output"
echo "checking in02 with existing output"
./tdm-generator.py tdm-tests/input02 output
diff tdm-tests/output02/sorted_documents.txt output/sorted_documents.txt
diff tdm-tests/output02/sorted_terms.txt output/sorted_terms.txt
diff tdm-tests/output02/td_matrix.txt output/td_matrix.txt
echo "done checking in02 with existing output"
