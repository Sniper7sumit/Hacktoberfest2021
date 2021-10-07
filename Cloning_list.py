def Cloning(list1):
    li_copy = []
    li_copy.extend(list1)
    return li_copy
list1 = [1,2,3,4,5,6]
list2 = Cloning(list1)
print("Before Cloning:", list1)
print("After Cloning:", list2)
