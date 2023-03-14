# uncompyle6 version 3.7.4
# Python bytecode 3.6 (3379)
# Decompiled from: Python 3.8.5 (default, Jan 27 2021, 15:41:15)
# [GCC 9.3.0]
# Embedded file name: challenge.py
# Compiled at: 2017-04-23 17:29:28
# Size of source mod 2**32: 1970 bytes

import hashlib

flag = [422690513718208603197180485123089552228212076789,
        44317394920663470439599331002781311566411591751,
        770532928004321317276586199312531973061171636152,
        485199322695171912133109002771794018221227648027,
        552217601566544758515102297425320266994028244549,
        1020655000011145935027846360132060520818390113750,
        1196151750138713746139996239500033013601661140394,
        462998648640265045181969745252763834104103361977,
        855167720509758161019464696519599315897915381578,
        285659669047782539467159484289884211950993880445,
        477429421877806872374252174118914073580937340807,
        1316616562982664008692722964252005506488452748146,
        1041012704324150835652886655287508314496841564428,
        444047727613521616138730246713219103138518320311,
        477429421877806872374252174118914073580937340807,
        1111942805099579814361048156301598870198262692071,
        227406986840443696682887170902576407689807301237,
        684329801336223661356952546078269889038938702779,
        477429421877806872374252174118914073580937340807,
        1291689539573382792298694352494321825326952217750,
        304942582444936629325699363757435820077590259883,
        1196151750138713746139996239500033013601661140394,
        61197560555531355947708244605936746875879897405,
        61197560555531355947708244605936746875879897405,
        1111644705301237875501860922880686912352243702634
]


def generate_numeric_hash(char):
    ''' This function is from the original script, it's the one that hashes '''
    m = hashlib.sha1()
    m.update(char.encode('utf-8'))
    return int(m.hexdigest(), 16)


# def main():
#     ''' This is the original main of the script'''
#     inp = input("> ")
#     # while (1):
#         # inp = bruteforce("abcdefghijklCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 25)
#     # if len(inp) != len(flag):
#     #     print('[-] not 25 chars long')
#     #     return
#     for i, c in enumerate(inp):
#         # print(reverse_numeric_hash(flag[i]))
#         temp = generate_numeric_hash(str(c))
#         print(temp)
#         if temp != flag[i]:
#             print('[-] not the flag')
#             return

#     print("flag : [%s]" % (inp))

def main():
    ''' This is my work around to force-brute the hashes '''
    res = ""
    p = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-!?;.,:*%^$&é(-èçà)°=+}]@^/`|[{#~"

    for n in range(25):
        for i, c in enumerate(p):
            temp = generate_numeric_hash(str(c))
            if temp == flag[n]:
                print(f"found char {n}: {c}")
                res += c
    print(f"\nThe flag is: {res}")


if __name__ == '__main__':
    main()