import math

def judge_square_sum(c):
    left = 0
    right = int(math.sqrt(c))  # Use int to avoid float issues
    
    while left <= right:
        current_sum = left * left + right * right
        if current_sum == c:
            return True
        elif current_sum < c:
            left += 1
        else:
            right -= 1
            
    return False

# Test cases
c1 = 5
c2 = 3

print(f"judge_square_sum({c1}) = {judge_square_sum(c1)}")  # Output: True
print(f"judge_square_sum({c2}) = {judge_square_sum(c2)}")  # Output: False