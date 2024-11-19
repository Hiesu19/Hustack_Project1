# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 8 - Analyze Code Submission of a Programming Contest
# ANALYZE_CODE_SUBMISSION	Partial		96	PYTHON3	23 / 25	

from collections import defaultdict

def time_to_seconds(time_str):
    h, m, s = map(int, time_str.split(":"))
    return h * 3600 + m * 60 + s
    
def count_submission_period(time_points, from_seconds, to_seconds):
    count = 0
    for time in time_points:
        if from_seconds <= time <= to_seconds:
            count += 1
    return count

# Hàm nhập 
submissions = []

while True:
    line = input().strip()
    if line == "#":
        break
    submissions.append(line)

#Bắt đầu tính toán
total_submissions = len(submissions)
error_submissions = 0
user_error_count = defaultdict(int)
user_points = defaultdict(lambda: defaultdict(int))
time_points = []

for submission in submissions:
    user, problem, time_point, status, point = submission.split()
    point = int(point)
    time_points.append(time_point)
    if status == "ERR":
        error_submissions += 1
        user_error_count[user] += 1
    if status == "OK":
        user_points[user][problem] = max(user_points[user][problem], point) # Chỉ lấy điểm cao nhất của mỗi bài thi
# --------------------------------------------------------------------------------

# Xử lý truy vẫn

while True:
    query = input().strip()
    if query == "#":
        break
    if query.startswith("?total_number_submissions"):
        print(total_submissions)
    if query == "?number_error_submision":
        print(error_submissions)
    if query.startswith("?number_error_submision_of_user"):
        _,user = query.split()
        print(user_error_count[user])
    if query.startswith("?total_point_of_user"):
        _,  user = query.split()
        print(sum(user_points[user].values()))
    if query.startswith("?number_submission_period"):
        _, from_time, to_time = query.split()
        print(count_submission_period(time_points,from_time,to_time))
