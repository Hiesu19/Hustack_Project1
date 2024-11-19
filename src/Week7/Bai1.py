# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 7 - Analyze sales order of an e-commerce company
# ANALYZE_SALES_ORDER_E_COMMERCE	Partial		86	PYTHON3	21 / 25

from collections import defaultdict

# Hàm nhập data
def nhapData():
    data = []
    while True:
        line = input().strip()
        if line == "#":
            break
        else:
            customer_id, product_id, price, shop_id, time_point = line.split()
            data.append((customer_id, product_id, int(price), shop_id, time_point))
    return data

# Hàm tính toán dữ liệu
def solve_data(datas):
    total_orders = len(datas)
    total_revenue = 0
    revenue_by_shop = defaultdict(int)
    customer_shop_revenue = defaultdict(int)
    revenue_by_time = []
    
    for customer_id, product_id, price, shop_id, time_point in datas:
        total_revenue += price
        revenue_by_shop[shop_id] += price
        customer_shop_revenue[(customer_id, shop_id)] += price
        revenue_by_time.append((time_point, price))
    
    # Sắp xếp revenue_by_time theo thời gian
    revenue_by_time.sort()
    
    return total_orders, total_revenue, revenue_by_shop, customer_shop_revenue, revenue_by_time

# Hàm nhập lệnh
def nhapQuerise(total_orders, total_revenue, revenue_by_shop, customer_shop_revenue, revenue_by_time):
    while True:
        query = input().strip();
        if query == "#":
            break
        elif query == "?total_number_orders":
            print(total_orders)
        elif query == "?total_revenue":
            print(total_revenue)
        elif query.startswith("?revenue_of_shop"): # Nếu bắt đầu bằng
            _, shop_id = query.split()
            print(revenue_by_shop.get(shop_id, 0))
        elif query.startswith("?total_consume_of_customer_shop"):
            _, customer_id, shop_id = query.split()
            print(customer_shop_revenue.get((customer_id, shop_id), 0))
        elif query.startswith("?total_revenue_in_period"):
            _, from_time, to_time = query.split()
            total_in_period = 0
            
            for time, price in revenue_by_time:
                if from_time <= time and time<= to_time:
                    total_in_period += price
            
            print(total_in_period)
    
# Nhập data cào dòng lệnh  
data = nhapData()


# Tính ra các kết quả cẩn thiết
total_orders, total_revenue, revenue_by_shop, customer_shop_revenue, revenue_by_time=solve_data(data)

nhapQuerise(total_orders, total_revenue, revenue_by_shop, customer_shop_revenue, revenue_by_time)
