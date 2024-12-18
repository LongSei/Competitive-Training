class Node: 
    def __init__(self, node_value): 
        self.value = node_value
        self.child_node = []
        self.parent_node = [None] * 21 
    
    def create_parent(self, parent: 'Node'): 
        self.parent_node[0] = parent
        current = parent
        for power_of_two in range(1, 21): 
            if self.parent_node[power_of_two - 1] is not None:
                self.parent_node[power_of_two] = current.parent_node[power_of_two - 1]
                current = self.parent_node[power_of_two]
    
    def add_child(self, child_node: 'Node'): 
        if child_node not in self.child_node:
            self.child_node.append(child_node)
        
def get_k_parent(node, k: int):
    for power_of_two in range(21, -1, -1):
        if k >= (1 << power_of_two): 
            if node.parent_node[power_of_two] is None:
                continue
            node = node.parent_node[power_of_two]
            k -= (1 << power_of_two) 
    return node
        
map_list = {}

def insert_node(parent: int, new_node: int): 
    if parent not in map_list:
        map_list[parent] = Node(parent)
    if new_node not in map_list:
        map_list[new_node] = Node(new_node)
    
    parent_node = map_list[parent]
    child_node = map_list[new_node]
    
    child_node.create_parent(parent_node)
    parent_node.add_child(child_node)
    
def remove_node(node : int): 
    if (node in map_list) == False: 
        return
    current_node = map_list[node]
    
    parent_node = current_node.parent_node[0]
    parent_node.child_node.remove(current_node)
    del map_list[node]
    
def query_k_parent(node: int, k: int): 
    if (node in map_list) is False:
        return 0
    ans = get_k_parent(map_list[node], k)
    return ans.value

if __name__ == "__main__": 
    t = int(input())
    for test in range(t): 
        map_list.clear()
        p = int(input())
        
        for i in range(p): 
            [x, y] = [int(w) for w in input().split()]
            insert_node(y, x)
            
        q = int(input())
        for i in range(q): 
            query = [int(w) for w in input().split()]
            if (query[0] == 1): 
                x = query[1]
                remove_node(x)
            elif (query[0] == 2): 
                [x, k] = query[1:3]
                print(query_k_parent(x, k))
            else: 
                [y, x] = query[1:3]
                insert_node(y, x)
        
