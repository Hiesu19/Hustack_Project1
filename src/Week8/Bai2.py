# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 8 - Citizen Data Analysis
# CITIZEN_DATA_ANALYZE	Partial		190	PYTHON3	17 / 20

from collections import defaultdict , deque

people = {}
birthdate_index = defaultdict(list)
parent = defaultdict(list)

while True:
    line = input().strip()
    if line == "*":
        break
    # Lưu thông tin cư dân
    code, dob, father, mother, is_alive, region = line.split()
    people[code] = {
            "dob": dob,
            "father": father,
            "mother": mother,
            "is_alive": is_alive,
            "region": region
        }
    
    birthdate_index[dob].append(code)
    if father != "0000000":
            parent[father].append(code)
    if mother != "0000000":
            parent[mother].append(code)

number_people = len(people)

def numberPeopleBornAt(time):
    return len(birthdate_index.get(time, []))

def mostAliveAncestor(code):
    visited = set()
    queue = deque([(code, 0)])  # Hàng đợi
    max_distance = 0
    
    while queue:
        current, distance = queue.popleft()
        if current in visited or current == "0000000":
            continue
        visited.add(current)
        max_distance = max(max_distance, distance) # Tìm max
        person = people.get(current)
        if not person:
            continue
        queue.append((person["father"], distance + 1)) # thêm bố
        queue.append((person["mother"], distance + 1)) #Thêm mẹ
    
    return max_distance

def numberPeopleBornBetween(from_date, to_date):
    count = 0
    for dob in birthdate_index:
        if from_date <= dob <= to_date:
            count += len(birthdate_index[dob])  # Cộng số lượng người có ngày sinh trùng nhau
    return count

def maxUnrelatedPeople():
    # tạo đồ thị qua hệ
    quanHe = defaultdict(set)
    
    # Xây dưng quan hệ cha/me/con
    for code, data in people.items():
        father = data["father"]
        mother = data["mother"]
        
        if father != "0000000":
            quanHe[code].add(father)
            quanHe[father].add(code)
        if mother != "0000000":
            quanHe[code].add(mother)
            quanHe[mother].add(code)
    
    # Tim mảng độc lập lớn nhẩt
    visited = set()
    independent_set = []
    
    for code in people:
        if code not in visited:
            independent_set.append(code) # Thêm người này vào
            visited.add(code)

            # Thêm Cha/ Me/ Con vào đã thăm
            for child in quanHe[code]:
                visited.add(child)
    
    return len(independent_set)

while True:
    query = input().strip()
    if query == "***":
        break
    if query == "NUMBER_PEOPLE":
        print(number_people)
    if query.startswith("NUMBER_PEOPLE_BORN_AT"):
        _,date = query.split()
        print(numberPeopleBornAt(date))
    if query.startswith("MOST_ALIVE_ANCESTOR"):
        _,  code = query.split()
        print(mostAliveAncestor(code))
    if query.startswith("NUMBER_PEOPLE_BORN_BETWEEN"):
        _, from_time, to_time = query.split()
        print(numberPeopleBornBetween(from_time,to_time))
    if query == "MAX_UNRELATED_PEOPLE":
        print(maxUnrelatedPeople())
