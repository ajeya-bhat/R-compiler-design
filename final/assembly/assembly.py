ot = ""
s = ""
e = open("optimized2.txt", "r")
er = e.read()
s = er
e.close()
Exp = s.split('\n')

sp_count = 0
counterloop = 100
variables = []

for i in range(0, len(Exp)):
    c = Exp[i]
    if(c.find("if") == -1):
        if(c.find("goto") != -1):
            branch = c.split(" ")
            print("b ",end=" ")
            print(branch[1],end=" ")
            print("")         
        elif(c.find("param") != -1):
            para = c.split(" ")
            print("str ",end=" ")
            print(para[1],end=" ")
            print(" , sp(",end=" ")
            print(sp_count,end=" ")
            sp_count += 1
            print(")")
            variables.append(para[1])
        elif(c.find("call") != -1):
            print("call ",end="")
            print(c[5 : c.find(",")],end=" ")
            #print(" ")
            print(c[c.find(",")  : ])         
        elif(c.find("=") != -1):
            #print("c",c)
            expression = c.split(" ")
            if(len(expression) == 3):
                if expression[2].isnumeric():
                    if expression[0].find('T')!=-1:
                        print("mov R",end="")
                        print(int(expression[0][expression[0].find('T') + 1:])%9+2,end = "")
                        print(", #",expression[2])
                    else:
                        print("mov R0",end = "")
                        print(", #{}".format(expression[2]))
                        print("str R0, ",expression[0])
                    

                
                elif expression[2].find('T')!=-1:
                    print("str",end=" ")
                    print("R",end = "")
                    print(int(expression[2][expression[2].find('T') + 1:])%9+2,end = "")
                    print(" , ",end = "")
                    print(expression[0])          
                else:
                    if expression[0] not in variables:
                        variables.append(expression[0])
                    print(expression[0],end = "")
                    print(" , ",end = "")                    
                    if(expression[2].find('T') == -1):
                        print("#",end= " ")
                        print(expression[2])
                    else: 
                        print("R",end = "")
                        print(int(expression[2][expression[2].find('T') + 1:])%9+2)
            elif len(expression) == 4 :
                print("orn ",end="")
                print("R",end = "")
                print(int(expression[0][expression[0].find('T') + 1:])%9+2,end = "")
                print(" , ",end = "")
                print("R",end = "")
                print(int(expression[3][expression[3].find('T') + 1:])%9+2,end = "")
                print(" , ",end = "")
                print("R",end = "")
                print(int(expression[3][expression[3].find('T') + 1:])%9+2)
                
            else: 
                r = "R"
                flag1=0
                flag2=0
                inti=int(expression[0][expression[0].find('T') + 1:])%9+2
                a = r  + str(inti)
                #print("expr",expression)
                arg1 = expression[2]
                opr = expression[3]
                arg2 = expression[4]                
                if(arg1.find('T') != -1):
                    intj=int(arg1[arg1.find('T') + 1:])%9+2 
                    arg1 = r + str(intj) 
                else:
                    if arg1.isnumeric():
                        arg1="#" + arg1
                    else:
                        variables.append(arg1)
                        print("ldr R9, {}".format(arg1))
                        arg1="R9"
                if(arg2.find('T') != -1):
                    intk=int(arg2[arg2.find('T') + 1:])%9+2 
                    arg2 = r + str(intk)
                else:
                    if arg2.isnumeric():
                        arg2="#"+arg2
                    else:
                        variables.append(arg1)
                        print("ldr R9, {}".format(arg2))
                        arg2="R9"                                                                    
                if(opr.find(">") != -1):
                    
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("bgt L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2                    
                if(opr.find("<") != -1):
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("blt L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2                                 
                if(opr.find("+") != -1):
                    print("add R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))                
                if(opr.find("-") != -1):
                    print("sub R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))                
                if(opr.find("*") != -1):
                    print("mul R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))                
                if(opr.find("/") != -1):
                    print("div R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))
                if(opr.find("<=") != -1):
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("ble L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2                    
                if(opr.find(">=") != -1):
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("bge L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2                    
                if(opr.find("==") != -1):
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("beq L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2                    
                if(opr.find("&&") != -1):
                    print("and R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))
                if(opr.find("||") != -1):
                    print("or R1 , ",end = "")
                    print(arg1,end = "")
                    print(" , ",end="")
                    print(arg2)
                    print("mov {} , R1".format(a))
                if(opr.find("!=")!=-1):
                    print("mov {} , #0".format(a))
                    print("cmp ",arg1,", ",arg2)	
                    print("bne L"+str(counterloop))
                    print("b L"+str(counterloop+1))
                    print("L"+str(counterloop)+":")
                    print("mov {} , #1".format(a))
                    print("L"+str(counterloop+1)+":")
                    counterloop+=2      
                
                                            
        else: 
            print(c)
    else:
        loops = c.split(" ")
        print("cmp ",end = "")
        print("R",end = "")
        print(str(int(loops[1][1:])%9+2),end = " ")
        print(", #0 ")
        print("bne",end=" ")
        print(loops[3])

    
print("\n.WORD ")
variables2 = []
check = 0
for i in variables:
    if("R" in i):
        variables.remove(i)
variables = list(set(variables))
for i in range(0, len(variables)):
        print(variables[i],end = " ")
        variables2.append(variables[i])
        if(i + 1 < len(variables)):
            print(" , ",end="")

print("")
