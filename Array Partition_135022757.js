/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    return nums.sort(function (a, b) {
        return a - b;
    }).filter(function (item, idx) {
        return (idx % 2 == 0);
    }).reduce(function (item, tot) {
        return tot + item;
    });
};
