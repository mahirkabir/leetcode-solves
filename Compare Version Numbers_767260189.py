class Solution:
    def cmp(self, n1, n2):
        num1 = int(n1)
        num2 = int(n2)
        
        if num1 == num2:
            return 0
        elif num1 > num2:
            return 1
        else:
            return -1
    
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")
        
        sz1 = len(v1)
        sz2 = len(v2)
        
        mnsz = min(sz1, sz2)
        for i in range(mnsz):
            res = self.cmp(v1[i], v2[i])
            if res != 0:
                return res
        
        if sz1 > sz2:
            for i in range(mnsz, sz1):
                if int(v1[i]) != 0:
                    return 1
                
        elif sz2 > sz1:
            for i in range(mnsz, sz2):
                if int(v2[i]) != 0:
                    return -1
            
        return 0
