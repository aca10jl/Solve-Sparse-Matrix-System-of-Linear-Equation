import numpy as np

m = 5000
n = 3000
dense = 0.001
s = int(m * n * dense)
print(s)

row = np.random.randint(m, size=s)
col = np.random.randint(n, size=s)
AA = np.random.random(s)
bb = np.random.random(m)

A = ""
for i in range(0,s):
	if i != s-1:
		A = A + str(row[i]) + " " + str(col[i]) + " " + str(AA[i]) + "\n"
	else:
		A = A + str(row[i]) + " " + str(col[i]) + " " + str(AA[i])

A_FML = open('A_FML.txt', 'w')
A_FML.write(A)
A_FML.close()

b = ""
for i in range(0,m):
	if i != m-1:
		b = b + str(bb[i]) + "\n"
	else:
		b = b + str(bb[i])

b_FML = open('b_FML.txt', 'w')
b_FML.write(b)
b_FML.close()