from block_finder import get_freq
from block_finder import calc_ci
from block_finder import other_ci

def main():
    test1 = 'AAACCBEEEEE'
    freq1 = get_freq(test1)
    if freq1['A'] != 3:
        print("Test1-A failed")
    if freq1['B'] != 1:
        print("Test1-B failed")
    if freq1['C'] != 2:
        print("Test1-C failed")

    ci1 = pow(3/11,2)+pow(2/11,2)+pow(1/11,2)+pow(5/11,2)

    if ci1 != calc_ci(freq1):
        print("Test1-ci failed")

    
    test2 = '''QPWK ALVR XCQZ IKGR BPFA EOMF LJMS DZVD HXCX JYEB IMTR QWNM
EAIZ RVKC VKVL XNEI CFZP ZCZZ HKML VZVZ IZRR QWDK ECHO SNYX
XLSP MYKV QXJT DCIO MEEX DQVS RXLR LKZH OV'''
    test2 = test2.replace(" ", "")
    test2 = test2.replace("\n", "")
    test2_num = []
    for char in test2:
        test2_num.append(ord(char) - 65)
    
    CI=[]
    for j in range(1, 11):

        # Create list of j arrays
        by_index = []
        for i in range(0, j):
            by_index.append([])
        
        # Sort all characters into the correct array
        for i, num in enumerate(test2):
            by_index[i%j].append(chr(ord(num)))

        # Calculate the CI for each index
        ci_index = []
        for column in by_index:
            freq = get_freq(column)
            ci_index.append(other_ci(freq))

            #for letter in column:
               # print(chr(letter+65),end="")
            #print()
                
        
        # Get mean CI for the block length
        print(j, round(sum(ci_index) / len(ci_index), 3))
        CI.append(sum(ci_index) / len(ci_index))
    

if __name__ == "__main__":
    main()