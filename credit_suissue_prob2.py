def securitiesBuying(z, security_value):
    no_of_stocks=0
   #participants code here
    rem=int(z[0])
    i=1
    lst=[]
    for item in security_value:
        lst.append([int(item), i])
        i+=1
    lst.sort(key=lambda x: x[0])
    i=0
    while rem>0 and i<len(lst):
        if(min(lst[i][1], int(rem/lst[i][0]))):
            no_of_stocks+=min(lst[i][1], int(rem/lst[i][0]))
            rem-=min(lst[i][1], int(rem/lst[i][0]))*lst[i][0]
        i+=1
    return no_of_stocks;


def main():
    z= input().split()
    security_value = []
    security_value = input().split()
    no_of_stocks_purchased=securitiesBuying(z,security_value)
    print(no_of_stocks_purchased)




if __name__ == '__main__':
    main()