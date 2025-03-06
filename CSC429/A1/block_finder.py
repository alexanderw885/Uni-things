def main():
    crypt = """COTKX NHWJG XABFZ PKGJC WGHMY QGEBJ YBGQX JIRDC VLVPP WNKSI PXAMT KUQFH
  QJDKV BGAET TEOGF TSTJV KHKIT SLOZY YBANB ZALLP IMTKH CMBCT YHPQZ NQUPK
 JFYPP EXDXF GUQMY WEEDX FMOQR ECYQV SHDNB MCAXN RZWNT NTJQK EHEXF CKMYS
 VFHRZ VWUSI JOVCO USKPB KFPRR QKPFN ZCRXN TTWKG SEUBM ZXURC QEEPP OKWNS
 HGEPL FKQLA TMWMK QBPKS ELDVY VPFAW ZSMDB MEFNE RSXWR GGMBE XDSFD IQRPI
 GNZTP TZACH HQDTT ASREJ DLTFL SJLGK JPJKU XIAGN MIAEU FNKVO GVPBX UOHFB
 IYQLM RZEJO GHQFS YOUUX BWVCB LFLUD GXJCE XEWQZ OHZML AK"""
    
    # Remove spaces
    crypt = crypt.replace(" ", "")
    crypt = crypt.replace("\n", "")


    CI = []
    CI.append(0) # block length starts at 1 but list is zero-indexed. now index value corresponds to block length

    # Loop through each block length
    for j in range(1, 101):

        # Create list of j arrays
        by_index = []
        for i in range(0, j):
            by_index.append([])
        
        # Sort all characters into the correct array
        for i, num in enumerate(crypt):
            new_char_index = ord(num)-(i//j) # -(i//j) accounts for each block incrementing all the chars by 1
            while new_char_index < ord('A'): # effectively mod26
                new_char_index += 26
            by_index[i%j].append(chr(new_char_index))

        # Test print
        '''
        for row in range(0, len(by_index[0])):
            for col in range(0, j):
                if row < len(by_index[col]):
                    print(by_index[col][row],end='')
            print()
        '''

        # Calculate the CI for each index
        ci_index = []
        for column in by_index:
            freq = get_freq(column)
            ci_index.append(other_ci(freq))
        
        # Get mean CI for the block length
        CI.append(sum(ci_index) / len(ci_index))
    
    # Print all possible candidates
    for i, ci in enumerate(CI):
        if ci > 0.06:
            print(i,":", ci)
    
    

def get_freq(line):
    freq = {}
    for char in line:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1
    return freq



# Old function, less accurate than other_ci
def calc_ci(freq):
    count = 0

    # Get total number of letters
    for letter in freq:
        count += freq[letter]
    
    # Calculate ci
    ci = 0
    for letter in freq:
        ci += pow((freq[letter]/count),2)
    
    return ci


def other_ci(freq):
    count = 0

    # Get total number of letters
    for letter in freq:
        count += freq[letter]
    
    # Calculate CI
    ci = 0
    for letter in freq:
        numerator = freq[letter]*(freq[letter]-1)
        denominator = count*(count-1)
        ci += numerator / denominator

    return ci
        
    

if __name__ == "__main__":
    main()