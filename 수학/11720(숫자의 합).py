n = int(input())
num_list = []
num = input(str())
for i in range(0, n):
    num_list.append(int(num[i]))

result = 0
for i in range(0, n):
    result += int(num_list[i])

print(result)
