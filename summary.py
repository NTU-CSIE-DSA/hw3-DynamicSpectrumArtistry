p3_num = 27
p4_num = 35

for i in range(p3_num):
    problem_num = f'3-{(i + 1):02}'
    with open(f'tests/{problem_num}.in', 'r') as file:
        lines = file.readlines()
    line = lines[0]
    numbers = [int(num) for num in line.split()]
    with open(f'tests/{problem_num}.out', 'r') as file:
        lines = file.readlines()
    print(f'P{problem_num}: V = {numbers[0]}, E = {numbers[1]}, SCC = {lines[0].strip()}, H-PATH = {lines[1].strip()}')
for i in range(p4_num):
    problem_num = f'4-{(i + 1):02}'
    with open(f'tests/{problem_num}.in', 'r') as file:
        lines = file.readlines()
    line = lines[0]
    numbers = [int(num) for num in line.split()]
    with open(f'tests/{problem_num}.out', 'r') as file:
        lines = file.readlines()
    print(f'P{problem_num}: V = {numbers[0]}, E = {numbers[1]}, SCC = {lines[0].strip()}, H-PATH = {lines[1].strip()}')
