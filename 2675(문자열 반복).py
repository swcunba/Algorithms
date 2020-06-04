t = int(input())

while(t):
    reps, s = input().split()
    txt = ''
    for i in s:
        txt += int(reps)*i

    print(txt)
    t -= 1
