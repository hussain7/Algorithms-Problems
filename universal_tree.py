sum=0
class node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        


root = node(0)
root.left =  node(1)
root.right = node(0)
root.right.left = node(1)
root.right.right = node(0)

def count_universal_tree(root):
    global sum
    if (root.left == None and root.right == None):
        sum += 1
        return True
    left_node = count_universal_tree(root.left)
    right_node = count_universal_tree(root.right)
    if ( (root.left.value == root.right.value) and left_node and right_node ):
        sum +=1
        return True
    
    return False
    
    
count_universal_tree(root)
