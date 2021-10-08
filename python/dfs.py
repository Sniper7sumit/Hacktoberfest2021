
#depth first search
arr=[
    [0,1,1,0,1],
    [0,0,0,0,1],
    [1,1,0,1,1],
    [1,1,0,1,1],
    [1,0,0,0,0]
]

x,y=(0,0)
visited=[]
def proto(array,visite,x_,y_):
    visite.append((x_,y_))
    stem=[]
    for i,j in (-1,0),(0,1),(1,0),(0,-1):
        if 0<=x_+i<len(array) and 0<=y_+j<len(array) and array[x_+i][y_+j]==0 and (x_+i,y_+j) not in visite:
            stem.append((x_+i,y_+j))
            
    for k in stem:
        x_=k[0]
        y_=k[1]
        proto(array,visite,x_,y_)
            

proto(arr,visited,x,y)
print(visited)


