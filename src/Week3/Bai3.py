# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 3 - Family Tree
# // FAMILY_TREE	Accept		50	PYTHON3	2 / 2	

# Hàm nhập family tree
def buildFamilyTree():
    family_tree = {}
    while True:
        line = input().strip()  #Tách dấu cách
        if line == '***':
            break
        child, parent = line.split()
        if parent not in family_tree:
            family_tree[parent] = []
        family_tree[parent].append(child) #Thêm con vào cha
    return family_tree  #{'Newman': ['Peter', 'Mark', 'David'], 'Thomas': ['Michael', 'Pierre']}

# Hàn tính số con cháu
def countDes(family_tree, person):
    #Không có trong gia phả trả về 0
    if person not in family_tree:
        return 0
    #Đệ quy để cho các con
    count = 0
    for child in family_tree[person]:
        count += 1 + countDes(family_tree, child)
    return count

# Hàm số thế hệ của hậu duệ
def countGen(family_tree, person):
    #Không có trong gia phả trả về 0
    if person not in family_tree:
        return 0
    #Đệ quy sô thế hệ , và chọn thế hệ lớn nhất
    max_depth = 0
    for child in family_tree[person]:
        max_depth = max(max_depth, countGen(family_tree, child))
    # Cộng 1 vì có tính chính nó
    return max_depth + 1

# Nhập đầy vào phần xủa lý
def processQueries(family_tree):
    
    while True:
        line = input().strip()
        if line == '***':
            break
        cmd, person = line.split()
        if cmd == 'descendants':
            print(countDes(family_tree, person))
        elif cmd == 'generation':
            print( countGen(family_tree, person))

# Hàm chính
def main():
    family_tree = buildFamilyTree()
    processQueries(family_tree)
main()
