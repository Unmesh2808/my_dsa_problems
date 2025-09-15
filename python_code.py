def searchMatrix(nested_list, target):
    m = len(nested_list)
    for i in range(m):
        if target in nested_list[i]:
            return True
        
    return False

def findduplicate(mylist):
    m1 = [0]*len(mylist)
    n=0
    for i in mylist:
        m1[i] += 1
    
    for k in range(len(mylist)):
        if m1[i]>1:
            n=i
            break
    
    return n

if __name__ == "__main__":

    data = [[1,2,3,4],[2,3,4,5],[5,6,7,8]]
    mylist = [1,4,5,3,2,5]
    print(findduplicate(mylist))
    # print(searchMatrix(data,8))


    
