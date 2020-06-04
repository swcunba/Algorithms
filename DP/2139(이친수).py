n = int(input())

if n == 1:
    print(1)

elif n == 2:
    print(1)

elif n == 3:
    print(2)

else:
    #(n-3) + (n-1자리 이친수 개수)
    num_list = [1, 1]
    for i in range(2, n):
        temp = num_list[i-2] + num_list[i-1]
        num_list.append(temp)
    print(num_list[n-1])

