from block_finder import get_freq
from block_finder import other_ci

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

    key_len = 6

    # Create english frequency dict for calculating CI
    english_freq = {'A':0.082,'B':0.015,'C':0.028,'D':0.043,
                    'E':0.127,'F':0.022,'G':0.020,'H':0.061,
                    'I':0.070,'J':0.0015,'K':0.0077,'L':0.040,
                    'M':0.024,'N':0.067,'O':0.075,'P':0.019,
                    'Q':0.00095,'R':0.06,'S':0.063,'T':0.091,
                    'U':0.028,'V':0.0098,'W':0.024,'X':0.0015,
                    'Y':0.020,'Z':0.00074,}
    

    # Create list of j arrays
    by_index = []
    for i in range(0, key_len):
        by_index.append([])
    
    # Sort all characters into the correct array
    for i, num in enumerate(crypt):
        new_char_index = ord(num)-(i//key_len) # -(i//key_len) accounts for each block incrementing all the chars by 1
        while new_char_index < ord('A'): # effectively mod26
            new_char_index += 26
        by_index[i%key_len].append(chr(new_char_index))

    full_key=[]
    for index in by_index:
        full_key.append(fancier_ci(english_freq,index))


    for char in full_key:
        print(char,end=' ')
    print()
    for char in full_key:
        print(chr(char+65),end="  ")
    print()

    for i in range(key_len):
        letter = crypt[i]
        number = ord(letter) - full_key[i]
        if number < ord('A'):
            number += 26
        letter = chr(number)
        print(letter,end='')

    for i in range(key_len):
        letter = crypt[i+6]
        number = ord(letter) - full_key[i] - 1
        if number < ord('A'):
            number += 26
        letter = chr(number)
        print(letter,end='')





# Returns the best key for that index
def fancier_ci(english, cipher):
    best_key = -1
    best_ci = 10


    for key in range(26):

        # Add key to ciphertext
        key_cipher=[]
        for char in cipher:
            new_char = ord(char) + key
            if new_char > ord('Z'):
                new_char -= 26
            key_cipher.append(chr(new_char))

        cipher_freq = get_freq(key_cipher)
 
        # Calculate combined CI
        current_ci = 0
        for i in cipher_freq: 
            current_ci += (cipher_freq[i] / len(cipher))*english[i]

        # Check if this is the new best key
        if abs(current_ci - 0.65) < abs(best_ci - 0.65):
            best_ci = current_ci
            best_key = key
    #print(chr(best_key+65))
    print(best_ci)
    return(best_key)
        

if __name__ == "__main__":
    main()