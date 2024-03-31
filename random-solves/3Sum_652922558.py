class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        print(nums)
        n = len(nums)
        if n <= 2:
            return []
        
        dict = {}
        for i in range(n):
            num = nums[i]
            if num not in dict:
                dict[num] = [i]
            else:
                dict[num].append(i)
         
        # print(dict)
        # dict_res = {}
        res = []
        pre_i = 1000000
        for i in range(n):
            if pre_i == nums[i]:
                continue
            pre_i = nums[i]
            pre_k = 1000000
            for k in range(i + 2, n):
                if pre_k == nums[k]:
                    continue

                target = -(nums[k] + nums[i])
                if target in dict:
                    print(i, k, "i-k")
                    print(nums[i], nums[k], target, "target")
                    dict_js = dict[target]
                    if (target == nums[i] or target == nums[k]):
                        if len(dict_js) == 1:
                            continue
                        else:
                            j = dict_js[1]
                            print(i, j, k, "i-j-k-1")
                            if not (i <= j and j <= k):
                                continue
                            # dict_res[[i, j, k]] = 1
                            res.append([nums[i], nums[j], nums[k]])
                            pre_k = nums[k]
                    else:
                        j = dict_js[0]
                        # dict_res[[i, j, k]] = 1
                        if not (i <= j and j <= k):
                            continue
                        res.append([nums[i], nums[j], nums[k]])
                        pre_k = nums[k]
        
        # for key in dict_res:
            # res.append(key)
            
        return res
