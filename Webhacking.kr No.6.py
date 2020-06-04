#!/usr/bin/env python
# coding: utf-8

# In[9]:


import base64
import sys #파이썬에서 제공하는 변수&함수 직접 제어할 수 있게 해주는 모듈(예: 경로설정)
val_id = "admin"
val_pw = "nimda"


# In[10]:


val_id = val_id.encode("utf-8") #유니코드로 전환시켜서 이상한 문장 나오지 않도록 함
val_pw = val_pw.encode("utf-8")
i = 0
for i in range(20):#소스에 나와있는대로 20번 base64 인코딩(문자 코드를 기준으로 문자를 코드로 변환)
    val_id = base64.b64encode(val_id)
j = 0
for j in range(20):
    val_pw = base64.b64encode(val_pw)
    
val_id = val_id.decode() ##base64로 인코딩된 것 디코딩(코드 다시 문자로 변환)
val_pw = val_pw.decode()

val_id.replace("1", "!") #소스의 규칙대로 디코딩된 id와 pw 특수문자로 변환
val_id.replace("2", "@")
val_id.replace("3", "$")
val_id.replace("4", "^")
val_id.replace("5", "&")
val_id.replace("6", "*")
val_id.replace("7", "(")
val_id.replace("8", ")")

val_pw.replace("1", "!")
val_pw.replace("2", "@")
val_pw.replace("3", "$")
val_pw.replace("4", "^")
val_pw.replace("5", "&")
val_pw.replace("6", "*")
val_pw.replace("7", "(")
val_pw.replace("8", ")")

print("id:" + val_id)
print("pw:" + val_pw)


# In[ ]:




