def is_sum_num_exist(num1, num2, num3):
    is_exist = False
    if num1 == num2 + num3:
        is_exist = True
    elif num2 == num1 + num3:
        is_exist = True
    elif num3 == num1 + num2:
        is_exist = True
        
    return is_exist
        

def is_multiply_num_exist(num1, num2, num3):
    is_exist = False
    if num1 == num2 * num3:
        is_exist = True
    elif num2 == num1 * num3:
        is_exist = True
    elif num3 == num1 * num2:
        is_exist = True
        
    return is_exist


def easy_to_solve_expressions(num1, num2, num3):
    answer = 3
    
    is_sum_exist = is_sum_num_exist(
        num1=num1, num2=num2, num3=num3
    )
    
    is_multiply_exist = is_multiply_num_exist(
        num1=num1, num2=num2, num3=num3
    )
    
    if is_sum_exist:
        answer = 1
    elif is_multiply_exist:
        answer = 2
    
    return answer


if __name__ == "__main__":
    num1, num2, num3 = map(int, input().split())
    
    print(easy_to_solve_expressions(num1=num1, num2=num2, num3=num3))