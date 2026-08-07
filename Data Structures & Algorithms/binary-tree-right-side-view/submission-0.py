# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        solution = []
        queue = deque()

        queue.append(root)

        while queue:
            rightSide = None
            
            for i in range(len(queue)):
                node = queue.popleft()
                if node:
                    rightSide = node #after the loop, it will have the last item
                    queue.append(node.left)
                    queue.append(node.right)
            if rightSide:
                solution.append(rightSide.val)
        
        return solution;
            

                