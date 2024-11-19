# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 1 - Convert hh:mm:ss to seconds
# // CONVERT_HH_MM_SS_2_SECOND	Accept		140	PYTHON3	7 / 7	

#PYTHON 
n = input()

def check(n):
    n = n.split(":")
    for i in n:
        if len(i) != 2:
            return 0
    if int(n[0]) >23 or int(n[0]) < 0:
        return 0
    if int(n[1]) >59 or int(n[1]) < 0:
        return 0
    if int(n[2]) >59 or int(n[2]) < 0:
        return 0
    return 1

if check(n):
    n = n.split(":")
    print(int(n[0])*60*60 + int(n[1])*60 + int(n[2]))
else:
    print("INCORRECT")
        
