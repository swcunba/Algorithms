#!/usr/bin/env python
# coding: utf-8

# In[13]:


a, b, c = map(int, input().split()) ##맵 함수 사용하여 전부 int 적용, 공백을 기준으로 나눔.


# In[14]:


if a > b and a > c:
    if b > c:
        print(b)
    elif b < c:
        print(c)
    else:
        print (b)
if a < b and a < c:
    if b > c:
        print(c)
    elif b < c:
        print (b)
    else:
        print(b)
elif a == b or a == c:
    print(a)
elif a > b and a < c:
    print(a)
elif a < b and a > c:
    print(a)
    


# In[ ]:




