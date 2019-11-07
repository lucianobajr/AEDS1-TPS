import random
t=35
arq=open("%d.txt"%t,"w")
peso=[random.randint(0,50)for i in range(t)]
valor=[random.randint(0,50)for i in range(t)]
arq.write("%d\n"%t)
for i in range(t):
    arq.write("%d %d\n"%(peso[i],valor[i]))
arq.close()
