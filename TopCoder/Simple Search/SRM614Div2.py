#
class MinimumSquareEasy(object):
    def minArea(self, x, y):
        n = len(x)
        cands = []
 
        for i in xrange(n - 1):
            for j in xrange(i + 1, n):
                cx = x[:i] + x[i + 1:j] + x[j + 1:]
                cy = y[:i] + y[i + 1:j] + y[j + 1:]
 
                min_x, max_x = min(cx) - 1, max(cx) + 1
                min_y, max_y = min(cy) - 1, max(cy) + 1
 
                if max_x - min_x > max_y - min_y:
                    cands.append(max_x - min_x)
                else:
                    cands.append(max_y - min_y)
 
        return min(cands) ** 2
