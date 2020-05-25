f=open("output.txt","r")
flag = 0
string = ""
for x in f:
	if(x=="Optimized Intermidiate code is:\n" or x=="No optimization can be performed\n"):
		flag = 1
	if(flag==1 and x!="Optimized Intermidiate code is:\n" and x!="No optimization can be performed\n" and x!="Quadruples\n"):
		string+=x
	if(x=="Quadruples\n" and flag==1):
		flag = 0
l = string.split("\n")
string = ""
for i in l:
	l1 = i.split("\t")
	for j in l1:
		if(j!="" and j[0]!="\n"):
			string+=j
			string+="\n"
print(string[0:-1])
