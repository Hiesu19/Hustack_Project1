# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 1 - Extract Year, Month, Date from a String YYYY-MM-DD
# // EXTRACT_YYYY_MM_DD	Accept		140	PYTHON3	7 / 7	

n = input()

def check(n):
    if len(n) != 10:
        return 0
    n = n.split("-")
    if len(n) !=3:
        return 0
    if len(n[0]) != 4:
        return 0
    if int(n[1]) < 1 or int(n[1])>12:
        return 0 
    if int(n[2]) < 1 or int(n[2]) >31:
        return 0
    return 1

if check(n):
    n=n.split("-")
    print(n[0] + " " + str(int(n[1])) + " " + str(int(n[2])))
else:
    print("INCORRECT")
