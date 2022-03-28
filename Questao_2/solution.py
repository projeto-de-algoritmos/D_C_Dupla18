import heapq

def kClosest(points, k):

    minHeap = []
    maxHeap = []
    
    for x, y in points:
        dist_pitagoras = ((x ** 2) + (y ** 2))**(1/2) # h^2 = x^2 + y^2
        minHeap.append([dist_pitagoras, x, y])
    
    heapq.heapify(minHeap)
    
    for i in range(k):
        dist_pitagoras, x, y = heapq.heappop(minHeap)
        maxHeap.append([x,y])
    
    return maxHeap

# Variáveis de Entrada (Input)

# Modifique aqui os valores de entrada, caso deseje;
points = [[3, 3], [5, -1], [-2, 4]]
K = 2
 
print(kClosest(points, K))