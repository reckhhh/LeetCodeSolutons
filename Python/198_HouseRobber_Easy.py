'''
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
    
    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
    
    Tags: Dynamic Programming
    
    Explanation of the Recursive Formula:
    
    By using Dynamic Programming, we can get the maximum amount of money step by step.
    
    For every house along the street, there are two situations,
    
    1. If the previous house had been robbed, we can't rob the current house,
        currentMaxValue = max(previousNoRobbery, previousYesRobbery);
        
    2. If the previous house hadn't been robbed, we can rob the current house,
        currentMaxValue = moneyOfCurrentHouse + previousNoRobbery
'''
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        preYes = 0
        preNo = 0
        
        for num in nums:
            preNoTemp = preNo
            preNo = max(preNo, preYes)
            preYes = preNoTemp + num
        
        return max(preNo, preYes)