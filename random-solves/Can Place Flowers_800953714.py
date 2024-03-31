class Solution:
    def canPlaceFlowers(self, FB: List[int], n: int) -> bool:
        FB = [0] + FB + [0]
        st = 0
        for i in range(1, len(FB)):
            if FB[i] == 0:
                if st == -1:
                    st = i
            elif st != -1:
                how_many = i - st
                n -= int((how_many - 1) / 2)
                st = -1
                
        if st != -1:
            n -= int((len(FB) - st - 1) / 2)
            
        # int(n)
        return n <= 0
