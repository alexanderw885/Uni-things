from block_finder import get_freq
from block_finder import calc_ci
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
    output = ""
    for i, char in enumerate(crypt):
        number = ord(char)
        number -= i // 6

        while number < ord('A'):
            number += 26

        output += (chr(number))
    print(output)


if __name__ == "__main__":
    main()