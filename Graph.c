from collections import defaultdict, deque

def find_component_sizes(n, edges):
    # Build graph
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = set()
    component_sizes = []

    def bfs(start):
        queue = deque([start])
        visited.add(start)
        size = 0
        while queue:
            node = queue.popleft()
            size += 1
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        return size

    # Check all nodes from 1 to 2N
    for node in range(1, 2 * n + 1):
        if node not in visited and graph[node]:
            size = bfs(node)
            if size >= 2:
                component_sizes.append(size)

    if not component_sizes:
        return (0, 0)

    return (min(component_sizes), max(component_sizes))


# Contoh penggunaan
if __name__ == "__main__":
    n = 4
    edges = [
        (1, 5),
        (2, 6),
        (3, 6),
        (4, 7),
        (7, 8)
    ]
    smallest, largest = find_component_sizes(n, edges)
    print("Komponen Terkecil:", smallest)
    print("Komponen Terbesar:", largest)
