class FoxAndClassroom:
    def ableTo(_, n, m):
        visited = set() # a set of visited seats
        (x,y) = (0,0)
        while (x,y) not in visited:
            visited.add( (x,y) ) # add to visited set (mark as visited)
            (x, y) = ( (x+1) % n, (y+1) % m ) # move to next seat
         
        # if there is any seat that wasn't visited, return Impossible:
        for i in range(0,n):
            for j in range(0,m):
                if (i,j) not in visited:
                    return "Impossible"
        return "Possible"