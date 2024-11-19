# // Nguyen Thai Hieu - Project1 - 2024.1
# Week 7 - Bank Transaction
# BANK_TRANS_BASIC	Partial		200	PYTHON3	20 / 25

from collections import defaultdict

# Dữ liệu lưu trữ
data = [] 
transactions_to = defaultdict(list) # giao dịch gửi đi {a: [(b, 100)]}
accounts = set() # danh sách tài khoản

# Hàm đọc và lưu trữ thông tin giao dịch
def read_data():
    while True:
        line = input().strip()
        if line == "#":
            break
        else:
            from_acc, to_acc, money, time_point, atm = line.split()
            
            money = int(money)
            data.append((from_acc, to_acc, money, time_point, atm))
            transactions_to[from_acc].append((to_acc, money))
            accounts.add(from_acc)
            accounts.add(to_acc)

def inspect_cycle(acc, k):
    visited = set()  # Để theo dõi các tài khoản đã thăm
    stack = []  # Để theo dõi chuỗi các tài khoản đang thăm
    check = [False]  #lưu kết quả chu trình

    # Hàm đệ quy DFS để tìm chu trình
    def dfs(acc, path): #path là đường đi
        if len(path) == k:
            if path[-1] == acc:  # Nếu tài khoản cuối cùng là tài khoản bắt đầu
                check[0] = True
            return
        
        # Nếu tài khoản đã thăm thoát
        if acc in visited:
            return
        visited.add(acc)
        
        # dfs
        for next_acc, _ in transactions_to.get(acc, []):
            if check[0]:
                return
            #đệ quy
            dfs(next_acc, path + [next_acc]) # nối thêm path
        
        visited.remove(acc)
    
    # bắt từ tài khoản acc
    dfs(acc, [acc])
    return 1 if check[0] else 0
    
def solve_data():  # Chỉ tính các số tổng quát
    number_transactions = len(data)
    total_money_transaction = sum(t[2] for t in data)
    sort_acc = " ".join(sorted(accounts))  # string đã sắp xếp
    return number_transactions, total_money_transaction, sort_acc

# Hàm nhập lệnh
def nhapQuerise():
    while True:
        query = input().strip()
        if query == "#":
            break
        
        elif query == "?number_transactions":
            print(number_transactions)
            
        elif query == "?total_money_transaction":
            print(total_money_transaction)
            
        elif query.startswith("?list_sorted_accounts"):
            print(sort_acc)
            
        elif query.startswith("?total_money_transaction_from"):
            _, acc = query.split()
            total_money_from_account = sum(money for _, money in transactions_to[acc])
            print(total_money_from_account)
            
        elif query.startswith("?inspect_cycle"):
            _, acc, k_str = query.split()
            k = int(k_str)
            print(inspect_cycle(acc, k))

# Đọc dữ liệu, tính toán các giá trị tổng quát và thực thi các truy vấn
read_data()
number_transactions, total_money_transaction, sort_acc = solve_data()
nhapQuerise()
