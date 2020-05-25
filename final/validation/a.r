#Erroneous code
#a=
#if(){
# a=1
#}

#a=1
#if(a>){
# a=1
#}

#a=1
#if(a>1{
# b=2
#}

#b=2
#if(b>2){
#b=b+1}
#a=2
#else{
#b=1}

#a=1
#if(a>2){
# a=2++3
#}
#else{
# a=2+4


#Proper Code

a=0
for(i in 1:5)
	a=a+1
while(a<1)
    a=a-1

a=1
if(a==2)
 a=1 
else
  a=2

a=1
print("HI")
print(a)

a=1 && 2 || 3

a=1
if(a>2){
	for(i in 1:3){
		while(1<2){
			a=2
		}
	}
}
else{
	while(a<2){
		a=a-1
		while(2>3){
			a=3
		}
		for(i in 3:5){
			a=a*1
		}
	}
}
